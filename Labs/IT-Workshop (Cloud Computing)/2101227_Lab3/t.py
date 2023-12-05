import boto3
import time

# Configuration
startup_script = 'startup_script.sh'
s3_bucket_name = 'peakyblinders'
security_group_name = 'web-tier'
instance_key_name = 'Vishal'
ec2_role_name = 'Devil'
ami_id = 'ami-0ded8326293d3201b'  # Replace with your desired AMI ID

# Initialize Boto3 client
ec2 = boto3.client('ec2')

# User data script
user_data_script = '''#!/bin/bash
sudo yum install httpd -y
sudo service httpd start
sudo aws s3 sync s3://{bucket_name}/website/ /var/www/html/
'''


def wait_for_instance_running(instance_id):
    print(f"Waiting for instance {instance_id} to reach 'running' state...")
    waiter = ec2.get_waiter('instance_running')
    waiter.wait(InstanceIds=[instance_id])
    print(f"Instance {instance_id} is now in 'running' state.")


def launch_ec2_instance(instance_type):
    response = ec2.run_instances(
        ImageId=ami_id,
        InstanceType=instance_type,
        KeyName=instance_key_name,
        SecurityGroups=[security_group_name],
        MaxCount=1,
        MinCount=1,
        IamInstanceProfile={'Name': ec2_role_name},
        UserData=user_data_script.format(bucket_name=s3_bucket_name)
    )
    instance_id = response['Instances'][0]['InstanceId']
    wait_for_instance_running(instance_id)
    return instance_id


def list_running_instances():
    instances = []
    response = ec2.describe_instances(
        Filters=[{'Name': 'instance-state-name', 'Values': ['running']}])
    for reservation in response['Reservations']:
        instances.extend(reservation['Instances'])
    return instances


def stop_and_terminate_instances(instance_ids):
    print("Stopping and terminating instances...")
    ec2.terminate_instances(InstanceIds=instance_ids)
    waiter = ec2.get_waiter('instance_terminated')
    waiter.wait(InstanceIds=instance_ids)
    print("Instances terminated.")


def main():
    try:
        # Launch instances
        instance_type_list = ['t2.micro', 't2.nano', 't2.nano']
        instance_ids = [launch_ec2_instance(
            instance_type) for instance_type in instance_type_list]

        # List running instances
        running_instances = list_running_instances()
        print("Running instances:")
        for instance in running_instances:
            print(
                f"Instance ID: {instance['InstanceId']}, Status: {instance['State']['Name']}")

        # Wait for a while
        print("Waiting for instances to run for a while...")
        time.sleep(120)

        # Stop and terminate instances
        stop_and_terminate_instances(instance_ids)
    except Exception as e:
        print("An error occurred:", str(e))


if __name__ == "__main__":
    main()












# import boto3
# import time

# startup_script = 'startup_script.sh'
# s3_bucket_name = 'peakyblinders'
# security_group_name = 'web-tier'
# instance_key_name = 'Vishal'
# ec2_role_name = 'Devil'

# ec2 = boto3.client('ec2')

# script ='''#!/bin/bash\n
# sudo yum install httpd -y\n
# sudo service httpd start
# # used to synchronize the contents of a local directory with an Amazon S3 bucket.\n
# sudo aws s3 sync s3://peakyblinders/website/ /var/www/html/'''

# # Launch t2.micro Amazon Linux instance
# Instance1 = ec2.run_instances(
#     ImageId='ami-0ded8326293d3201b',  
#     InstanceType='t2.micro',
#     KeyName=instance_key_name,
#     SecurityGroups=[security_group_name],
#     MaxCount=2,
#     MinCount=2,
#     IamInstanceProfile={
#         'Name': ec2_role_name
#     },
#     UserData=script
# )

# inst = []
# for i in range(2):
#     instance_id_micro = Instance1['Instances'][i]['InstanceId']
#     inst.append(instance_id_micro)
# # instance_id_micro = Instance1['Instances'][0]['InstanceId']


# # # Launch two t2.nano Ubuntu instances
# # Instance2 = ec2.run_instances(
# #     ImageId='ami-0f5ee92e2d63afc18',  
# #     InstanceType='t2.nano',
# #     KeyName='Ubuntu',
# #     SecurityGroups=[security_group_name],
# #     MaxCount=0,
# #     MinCount=0,
# #     IamInstanceProfile={
# #         'Name': ec2_role_name
# #     }
# # )

# def check_instance_health(instance_id):
#     print(f"CHECKING HEALTH OF INSTANCE {instance_id}...")
#     waiter = ec2.get_waiter('instance_status_ok')
#     waiter.wait(InstanceIds=[instance_id])
#     time.sleep(2)
#     response = ec2.describe_instance_status(InstanceIds=[instance_id])
#     if 'InstanceStatuses' in response and len(response['InstanceStatuses']) > 0:
#         status = response['InstanceStatuses'][0]['InstanceStatus']['Status']
#         return status
#     return "Unknown"

# time.sleep(60)

# instances = ec2.describe_instances()
# for reservation in instances['Reservations']:
#     for instance in reservation['Instances']:
#         # inst.append(instance['InstanceId'])
#         print(f"Instance ID: {instance['InstanceId']}, State: {instance['State']['Name']}")
        
# instance_info = ec2.describe_instances(InstanceIds=[instance_id_micro])
# public_dns = instance_info['Reservations'][0]['Instances'][0]['PublicDnsName']
# print("Instance is now running .....")
# print("WEBSITE URL IS : ")
# print("http://" + public_dns)

# time.sleep(120)
# for i in inst:
#     health = check_instance_health(inst)
#     print(f"INSTANCE :  {inst[i]}  HEALTH : {health}")

# # Stop instances

# micro_instance_id = Instance1['Instances'][0]['InstanceId']
# ec2.stop_instances(InstanceIds=[micro_instance_id] )
# ec2.get_waiter('instance_stopped').wait(InstanceIds=[micro_instance_id] )
# ec2.terminate_instances(InstanceIds=[micro_instance_id] )
# ec2.get_waiter('instance_terminated').wait(InstanceIds=[micro_instance_id] )    


startup_script = 'startup_script.sh'
s3_bucket_name = 'peakyblinders'
security_group_name = 'web-tier'
instance_key_name = 'Vishal'
ec2_role_name = 'Devil'
ec2 = boto3.client('ec2')

script = '''#!/bin/bash\n
sudo yum install httpd -y\n
sudo service httpd start
# used to synchronize the contents of a local directory with an Amazon S3 bucket.\n
sudo aws s3 sync s3://peakyblinders/website/ /var/www/html/'''

# ---------------------Launch an t2.micro Amzon Linux instance.--------------------------------


def waitfn(instance_id):
    wt = ec2.get_waiter('instance_running')
    wt.wait(InstanceIds=[instance_id])
    print(f"\nINSTANCE {instance_id} IS RUNNING STATE.")


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
    # waitfn(instance_id)
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
