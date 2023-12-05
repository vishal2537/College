import boto3
import base64


def create_launch_template():
    ec2_client = boto3.client("ec2")
    startup_script = '''#!/bin/bash
sudo yum install httpd -y
sudo service httpd start
sudo aws s3 sync s3://peakyblinders/website/ /var/www/html/'''

    user_data = base64.b64encode(startup_script.encode()).decode('utf-8')

    response = ec2_client.create_launch_template(
        LaunchTemplateName="lt1",
        LaunchTemplateData={
            "ImageId": "ami-0ded8326293d3201b",
            "InstanceType": "t2.micro",
            "KeyName": "Vishal",
            "SecurityGroups": ["web-tier"],
            "IamInstanceProfile": {
                "Name": "Devil"
            },
            "UserData": user_data,
        },
    )
    return response['LaunchTemplate']['LaunchTemplateName']


def create_autoscaling_group(launch_template_name):
    asg_client = boto3.client("autoscaling")
    response = asg_client.create_auto_scaling_group(
        AutoScalingGroupName="auto-scale-gp",
        MinSize=0,
        MaxSize=2,  # Adjust as needed
        DesiredCapacity=2,
        LaunchTemplate={"LaunchTemplateName": launch_template_name},
        AvailabilityZones=["ap-south-1a", "ap-south-1b", "ap-south-1c"],
    )
    return response['AutoScalingGroupName']


def create_scaling_policies(asg_name):
    asg_client = boto3.client("autoscaling")

    # Create a scale-up policy
    asg_client.put_scaling_policy(
        AutoScalingGroupName=asg_name,
        PolicyName='scale-up-policy',
        PolicyType='TargetTrackingScaling',
        TargetTrackingConfiguration={
            'PredefinedMetricSpecification': {
                'PredefinedMetricType': 'ASGAverageCPUUtilization',
            },
            'TargetValue': 80,
        }
    )

    # Create a scale-down policy
    asg_client.put_scaling_policy(
        AutoScalingGroupName=asg_name,
        PolicyName='scale-down-policy',
        PolicyType='TargetTrackingScaling',
        TargetTrackingConfiguration={
            'PredefinedMetricSpecification': {
                'PredefinedMetricType': 'ASGAverageCPUUtilization',
            },
            'TargetValue': 40,
        }
    )


def create_cloudwatch_alarms(asg_name):
    cloudwatch_client = boto3.client("cloudwatch")

    # Create scale-up alarm
    cloudwatch_client.put_metric_alarm(
        AlarmName="scale-up-alarm",
        ComparisonOperator="GreaterThanThreshold",
        EvaluationPeriods=1,
        MetricName="CPUUtilization",
        Namespace='AWS/EC2',
        Period=60,
        Statistic="Average",
        Threshold=80,
        AlarmDescription="Scale up when CPU utilization is high",
        AlarmActions=[
            f'arn:aws:autoscaling:<region>:<account-id>:scalingPolicy/<policy-id>'],
        Dimensions=[
            {
                "Name": "AutoScalingGroupName",
                "Value": asg_name,
            }
        ],
    )

    # Create scale-down alarm
    cloudwatch_client.put_metric_alarm(
        AlarmName="scale-down-alarm",
        ComparisonOperator="LessThanThreshold",
        EvaluationPeriods=1,
        MetricName="CPUUtilization",
        Namespace='AWS/EC2',
        Period=60,
        Statistic="Average",
        Threshold=40,
        AlarmDescription="Scale down when CPU utilization is low",
        AlarmActions=[
            f'arn:aws:autoscaling:<region>:<account-id>:scalingPolicy/<policy-id>'],
        Dimensions=[
            {
                "Name": "AutoScalingGroupName",
                "Value": asg_name,
            },
        ],
    )


if __name__ == "__main__":
    launch_template_name = create_launch_template()
    asg_name = create_autoscaling_group(launch_template_name)
    create_scaling_policies(asg_name)
    create_cloudwatch_alarms(asg_name)