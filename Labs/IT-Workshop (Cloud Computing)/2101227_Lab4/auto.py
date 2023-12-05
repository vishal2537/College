import boto3
import base64
import time 

file = open("C:\\Users\\Lenovo\\Desktop\\college1\\Labs\\semester 5\\IT-workshop\\2101227_Assign_Lab4\\script.sh", "r")
src = '\n'.join(file)
ec2 = boto3.client('ec2')
autoscaling_client = boto3.client('autoscaling')
cloudwatch = boto3.client('cloudwatch')
encoded_src = base64.b64encode(src.encode()).decode('utf-8')


# defining some values for further use
GroupName = "auto-scale-gp"
TemplateName = "devil-auto-scaler"
KeyName = 'Vishal'
SecurityGroupIds = ['sg-07f28fef7a606ceda']
InstanceType = "t2.micro"
UserData = encoded_src
IamInstanceProfile = 'Devil'
minSize = 1
maxSize = 3

# instance type
# for launching template 
def launch_template(TemplateName, InstanceType, UserData, KeyName, SecurityGroup, IamInstacneProfile):
    template = ec2.create_launch_template(
        LaunchTemplateName=TemplateName,
        LaunchTemplateData={
            'ImageId': 'ami-0ded8326293d3201b',
            'InstanceType': InstanceType,
            'SecurityGroupIds': SecurityGroup,
            'KeyName': KeyName,
            'UserData': UserData,
            'IamInstanceProfile': {
                'Name': IamInstacneProfile
            },
        }
        
    )
    return template

# for creating autoscaling group


def create_autoscaling_group(TemplateName, GroupName, minSize, maxSize):
    autoscaling_group = autoscaling_client.create_auto_scaling_group(
        AutoScalingGroupName=GroupName,
        LaunchTemplate={
            'LaunchTemplateName': TemplateName,
            'Version': '$Default',
        },
        MinSize=minSize,
        MaxSize=maxSize,
        DesiredCapacity=2,
        # VPCZoneIdentifier='subnet-0fa516ae7d97502fa',
        AvailabilityZones=["ap-south-1a", "ap-south-1b", "ap-south-1c"],
    )
    return autoscaling_group


# for creating scaling policy
scale_in_policy = {
    'PolicyName': 'scale_in',
    'AutoScalingGroupName': GroupName,
    'AdjustmentType': 'ChangeInCapacity',   #criteria for increasing instance it can be request also
    'PolicyType': 'StepScaling',    # type target , simple
    'StepAdjustments': [
        {
            'MetricIntervalUpperBound': 0,
            'ScalingAdjustment': -1,
        },
    ],
    'Cooldown': 300,
}

scale_out_policy = {
    'PolicyName': 'scale_out',
    'AutoScalingGroupName': GroupName,
    'AdjustmentType': 'ChangeInCapacity',
    'PolicyType': 'StepScaling',
    'StepAdjustments': [
        {
            'MetricIntervalLowerBound': 0,
            'ScalingAdjustment': 1,
        },
    ],
    'Cooldown': 300,
}


template = launch_template(TemplateName, InstanceType,
                           UserData, KeyName, SecurityGroupIds, IamInstanceProfile)
print(template)
autoscaling_group = create_autoscaling_group(
    TemplateName, GroupName, minSize, maxSize)
print(autoscaling_group)

scale_in_policy_response = autoscaling_client.put_scaling_policy(
    **scale_in_policy)
scale_out_policy_response = autoscaling_client.put_scaling_policy(
    **scale_out_policy)

print(scale_in_policy_response)
print(scale_out_policy_response)


# create alarms
scale_out_alarm = {
    'AlarmName': 'HighUtilization',
    'ComparisonOperator': 'GreaterThanOrEqualToThreshold',
    'EvaluationPeriods': 1,
    'MetricName': 'CPUUtilization',   # graph of request or memory
    'Namespace': 'AWS/EC2', # for which service  type - sutocalling
    'Period': 60,
    'Statistic': 'Average',
    'Threshold': 50,
    'AlarmDescription': 'Alarm when server CPU exceeds 80%',
    'AlarmActions': [scale_out_policy_response['PolicyARN']],
    'Dimensions': [
        {
            'Name': 'AutoScalingGroupName',
            'Value': 'auto-scale-gp'
        }
    ]
}

scale_in_alarm = {
    'AlarmName': 'LowUtilization',
    'ComparisonOperator': 'LessThanOrEqualToThreshold',
    'EvaluationPeriods': 1,
    'MetricName': 'CPUUtilization',
    'Namespace': 'AWS/EC2',
    'Period': 60,
    'Statistic': 'Average',
    'Threshold': 20,
    'AlarmDescription': 'Alarm when server CPU falls short of 20%',
    'AlarmActions': [scale_in_policy_response['PolicyARN']],
    'Dimensions': [
        {
            'Name': 'AutoScalingGroupName',
            'Value': 'auto-scale-gp'
        }
    ]
}

cloudwatch.put_metric_alarm(**scale_in_alarm)
cloudwatch.put_metric_alarm(**scale_out_alarm)

time.sleep(100)

ec2_client = boto3.client('ec2')
# Use the describe_instances() method to get information about all running instances
response = ec2_client.describe_instances(
    Filters=[{'Name': 'instance-state-name', 'Values': ['running']}])

for reservation in response['Reservations']:
    for instance in reservation['Instances']:
        instance_id = instance['InstanceId']
        # Use Public DNS name, change to Private if needed
        dns_name = instance.get('PublicDnsName', 'N/A')
        print(f"Instance ID: {instance_id}, DNS Name: {dns_name}")