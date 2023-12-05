import boto3

s3_bucket_name = 'peakyblinders'
security_group_name = 'web-tier'
instance_key_name = 'Vishal'
ec2_role_name = 'Devil'      # s3 Access Role

ec2 = boto3.resource("ec2")

instances = ec2.create_instances(
    ImageId='ami-0ded8326293d3201b',
    MinCount=1,
    MaxCount=1,
    InstanceType="t2.micro",
    KeyName=instance_key_name,
    SecurityGroupIds=['sg-07f28fef7a606ceda'],
    UserData=open(
        "C:\\Users\\Lenovo\\Desktop\\college1\\Labs\\semester 5\\IT-workshop\\2101227_Assign_Lab5\\start_script.sh"
    ).read(),
)

print(instances)
instance = instances[0]
instance.wait_until_running()
instance.load()

print(instance.public_dns_name)
