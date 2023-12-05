import boto3
from time import sleep
import base64

script = '''#!/bin/bash\n
sudo yum install httpd -y\n
sudo service httpd start
# used to synchronize the contents of a local directory with an Amazon S3 bucket.\n
sudo aws s3 sync s3://peakyblinders/website/ /var/www/html/'''.encode('ascii')

script = base64.b64encode(script)


def create_autoscaling_group():
    client = boto3.client("autoscaling")
    response = client.create_auto_scaling_group(
        AutoScalingGroupName="auto-scale-gp",
        MinSize=0,
        DesiredCapacity=2,
        MaxSize=2,
        LaunchTemplate={"LaunchTemplateName": "lt1"},
        AvailabilityZones=["ap-south-1a", "ap-south-1b", "ap-south-1c"],
    )
    return response


def create_launch_template():
    client = boto3.client("ec2")
    response = client.create_launch_template(
        LaunchTemplateName="lt1",
        LaunchTemplateData={
            "ImageId": "ami-0ded8326293d3201b",
            "InstanceType": "t2.micro",
            "KeyName": "Vishal",
            "SecurityGroups": ["web-tier"],
            "IamInstanceProfile": {
                "Name": "Devil"
            },
            "UserData": script.decode('ascii'),
        },
    )
    return response


def create_up_scaling_policies():
    client = boto3.client("autoscaling")
    response = client.put_scaling_policy(
        AutoScalingGroupName="auto-scale-gp",
        PolicyName='scale-up-policy',
        PolicyType='StepScaling',
        AdjustmentType="ChangeInCapacity",
        StepAdjustments=[
            {
                "MetricIntervalLowerBound": 0,
                "ScalingAdjustment": 1,
            },
        ],
        Cooldown=200,
        MetricAggregationType='Average',
    )
    return response


def create_down_scaling_policies():
    client = boto3.client("autoscaling")
    response = client.put_scaling_policy(
        AutoScalingGroupName="auto-scale-gp",
        PolicyName='scale-down-policy',
        PolicyType='StepScaling',
        AdjustmentType="ChangeInCapacity",
        StepAdjustments=[
            {
                "MetricIntervalUpperBound": 0,
                "ScalingAdjustment": -1,
            }
        ],
        Cooldown=300,
        MetricAggregationType='Average',
    )
    return response


def create_cloudwatch_alarms(scale_up_policy_arn, scale_down_policy_arn):
    client = boto3.client("cloudwatch")
    response_up_alarm = client.put_metric_alarm(
        AlarmName="scale-up-alarm",
        ComparisonOperator="GreaterThanThreshold",
        EvaluationPeriods=1,
        MetricName="CPUUtilization",
        Namespace='AWS/EC2',
        Period=30,
        Statistic="Average",
        Threshold=80,
        AlarmDescription="Scale up when CPU utilization is high",
        AlarmActions=[scale_up_policy_arn],
        Dimensions=[
            {
                "Name": "AutoScalingGroupName",
                "Value": "auto-scale-gp",
            }
        ],
    )

    response_down_alarm = client.put_metric_alarm(
        AlarmName="scale-down-alarm",
        ComparisonOperator="LessThanThreshold",
        EvaluationPeriods=1,
        MetricName="CPUUtilization",
        Namespace='AWS/EC2',
        Period=30,
        Statistic="Average",
        Threshold=40,
        AlarmDescription="Scale down when CPU utilization is low",
        AlarmActions=[scale_down_policy_arn],
        Dimensions=[
            {
                "Name": "AutoScalingGroupName",
                "Value": "auto-scale-gp",
            },
        ],
    )


launch_template_response = create_launch_template()
create_autoscaling_group()
up_scaling_policy_response = create_up_scaling_policies()
down_scaling_policy_response = create_down_scaling_policies()
create_cloudwatch_alarms(
    up_scaling_policy_response["PolicyARN"], down_scaling_policy_response["PolicyARN"])
