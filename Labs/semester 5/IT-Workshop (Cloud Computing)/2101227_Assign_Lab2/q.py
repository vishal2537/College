import boto3
import time

s3_bucket_name = 'peakyblinders'
security_group_name = 'web-tier'
instance_key_name = 'Vishal'
ec2_role_name = 'Devil'      # s3 Access Role

# Initialize AWS clients
ec2_client = boto3.client('ec2')
s3_client = boto3.client('s3')

# startup script
startup_script = '''#!/bin/bash
sudo yum install httpd -y
sudo service httpd start
sudo aws s3 sync s3://peakyblinders/website/ /var/www/html/
'''

# Start an EC2 instance
instance = ec2_client.run_instances(
    ImageId='ami-0ded8326293d3201b',  # Replace with a valid AMI ID
    InstanceType='t2.micro',
    KeyName=instance_key_name,
    SecurityGroups=[security_group_name],
    MaxCount=1,
    MinCount=1,
    IamInstanceProfile={
        'Name': ec2_role_name
    },
    UserData=startup_script
)

instance_id = instance['Instances'][0]['InstanceId']

# Instance is running
while True:
    instance_info = ec2_client.describe_instances(InstanceIds=[instance_id])
    instance_state = instance_info['Reservations'][0]['Instances'][0]['State']['Name']
    if instance_state == 'running':
        break
    time.sleep(3)

# Public DNS of the instance
public_dns = instance_info['Reservations'][0]['Instances'][0]['PublicDnsName']
print("INSTANCE NOW RUNNING.\nPUBLIC DNS:", public_dns)

# Open public DNS in a browser
print("WEBSITE URL IS : ")
print("http://" + public_dns)