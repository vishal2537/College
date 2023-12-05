import boto3
import time

startup_script = 'startup_script.sh'
s3_bucket_name = 'peakyblinders'
security_group_name = 'web-tier'
instance_key_name = 'Vishal'
ec2_role_name = 'Devil'
ec2 = boto3.client('ec2')     # provide low level interface to aws services
 
script = '''#!/bin/bash\n
sudo yum install httpd -y\n
sudo service httpd start
# used to synchronize the contents of a local directory with an Amazon S3 bucket.\n
sudo aws s3 sync s3://peakyblinders/website/ /var/www/html/'''

# ---------------------Launch an t2.micro Amzon Linux instance.--------------------------------

def launch_instance(instance_type='t2.micro', ami_id='ami-0ded8326293d3201b'):
    rp = ec2.run_instances(
        ImageId=ami_id,
        InstanceType=instance_type,
        KeyName=instance_key_name,
        SecurityGroups=[security_group_name],
        MaxCount=1,
        MinCount=1,
        IamInstanceProfile={
            'Name': ec2_role_name
        },
        UserData=script
    )
    instance_id = rp['Instances'][0]['InstanceId']
    time.sleep(60)
    while True:
        instance_info = ec2.describe_instances(InstanceIds=[instance_id])
        temp = instance_info['Reservations'][0]['Instances'][0]['State']['Name']
        if temp == 'running':
            break
        time.sleep(2)
    # -------------------host an http server in the t2.micro instance. -------------------------
    
    pd = instance_info['Reservations'][0]['Instances'][0]['PublicDnsName']
    print("INSTANCE IN NOW RUNNING....")
    print("\nURL FOR WEBSITE : ")
    print("http://" + pd)
    return instance_id

    # ------------------------------------------------------------------------------------------
t2_1 = launch_instance()
t2_2 = launch_instance()
t2_3 = launch_instance()
instIds = [t2_1, t2_2, t2_3]

# ---------------------------------------------------------------------------------------------
# ---------------------------List all the running instances.-----------------------------------


def instanceList(instance_id):
    rp = ec2.describe_instances(InstanceIds=instance_id)
    instances = []
    for reservation in rp['Reservations']:
        instances.extend(reservation['Instances'])
    return instances


instances = instanceList(instIds)
print("\nLIST OF RUNNING INSTANCES :")
for i in instances:
    print(f"INSTANCE_ID: {i['InstanceId']}, STATUS: {i['State']['Name']}")

# -----------------------------------------------------------------------------------------------
# -------------------Check health of the running instances.------------------------------------


def check_instance_health(instance_id):
    print(f"\nHEALTH STATUS OF INSTANCE {instance_id} : ")
    wt = ec2.get_waiter('instance_status_ok')
    wt.wait(InstanceIds=[instance_id])
    time.sleep(5)
    rp = ec2.describe_instance_status(InstanceIds=[instance_id])
    if 'InstanceStatuses' in rp and len(rp['InstanceStatuses']) > 0:
        status = rp['InstanceStatuses'][0]['InstanceStatus']['Status']
        return status
    return "Unknown"


for instance_id in instIds:
    health = check_instance_health(instance_id)
    print(f"INSTANCE_ID {instance_id} HEALTH: {health}")

time.sleep(60)

# ----------------------------------------------------------------------------------------------
# -------------------------Stop the running instances.------------------------------------------


def stop_instances(instIds):
    ec2.stop_instances(InstanceIds=instIds)
    wt = ec2.get_waiter('instance_stopped')
    wt.wait(InstanceIds=instIds)
    print(f"\nINSTANCE {instIds} IS STOPPED.")


stop_instances(instIds)
print("INSTANCES STOPPED")

# -----------------------------------------------------------------------------------------------
# -------------------------Terminate the running instances.--------------------------------------

def terminate_instances(instIds):
    ec2.terminate_instances(InstanceIds=instIds)
    wt = ec2.get_waiter('instance_terminated')
    wt.wait(InstanceIds=instIds)

terminate_instances(instIds)
print("INSTANCE TERMINATED")
# ----------------------------------------- ------------------------------------------------------