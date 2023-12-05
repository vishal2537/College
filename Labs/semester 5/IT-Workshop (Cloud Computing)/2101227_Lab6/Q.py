import time
import boto3

client = boto3.client("elasticbeanstalk")

s3_bucket_name = 'peakyblinders1'
security_group_name = 'web-tier'
instance_key_name = 'Vishal'
ec2_role_name = 'Devil'      # s3 Access Role

client.create_application_version(
    ApplicationName="portfolioapp",
    AutoCreateApplication=True,
    Description="vishal_prajapati portfolio website",
    Process=True,
    SourceBundle={
        "S3Bucket": "peakyblinders1",
        "S3Key": "Portfolio.zip",
    },
    VersionLabel="v1",
)

while True:
    response = client.describe_application_versions(
        ApplicationName="portfolioapp",
        VersionLabels=[
            "v1",
        ],
        MaxRecords=1,
    )
    if response["ApplicationVersions"][0]["Status"] != "PROCESSED":
        print("Trying to create Application...")
        time.sleep(5)
    else:
        print("Succesfully created Application...")
        break

response = client.create_environment(
    ApplicationName="portfolioapp",
    CNAMEPrefix="vishal",
    EnvironmentName="portfolio-env",
    SolutionStackName="64bit Amazon Linux 2 v5.8.5 running Node.js 18",
    VersionLabel="v1",
    OptionSettings=[
        {
            "Namespace": "aws:autoscaling:launchconfiguration",
            "OptionName": "IamInstanceProfile",
            "Value": "Devil",
        },
        {
            "Namespace": "aws:autoscaling:launchconfiguration",
            "OptionName": "InstanceType",
            "Value": "t2.micro",
        },
        {
            "Namespace": "aws:autoscaling:launchconfiguration",
            "OptionName": "EC2KeyName",
            "Value": "Vishal",
        },
        {
            "Namespace": "aws:autoscaling:launchconfiguration",
            "OptionName": "ImageId",
            "Value": "ami-097e7acc1d0c8b1b9",
        },
        {
            "Namespace": "aws:autoscaling:launchconfiguration",
            "OptionName": "SecurityGroups",
            "Value": "sg-06a3c78a81d0056da",
        },
        {
            "Namespace": "aws:autoscaling:trigger",
            "OptionName": "Statistic",
            "Value": "Average",
        },
        {
            "Namespace": "aws:autoscaling:trigger",
            "OptionName": "Period",
            "Value": "1",
        },
        {
            "Namespace": "aws:autoscaling:trigger",
            "OptionName": "UpperThreshold",
            "Value": "80",
        },
        {
            "Namespace": "aws:autoscaling:trigger",
            "OptionName": "UpperBreachScaleIncrement",  
            "Value": "1",
        },
        {
            "Namespace": "aws:autoscaling:trigger",
            "OptionName": "MeasureName",
            "Value": "CPUUtilization",
        },
        {
            "Namespace": "aws:autoscaling:trigger",
            "OptionName": "LowerThreshold",
            "Value": "20",
        },
        {
            "Namespace": "aws:autoscaling:trigger",
            "OptionName": "LowerBreachScaleIncrement",
            "Value": "-1",
        },
        {
            "Namespace": "aws:autoscaling:asg",
            "OptionName": "Availability Zones",
            "Value": "Any 2",
        },
        {
            "Namespace": "aws:autoscaling:asg",
            "OptionName": "MaxSize",
            "Value": "3",
        },
        {
            "Namespace": "aws:autoscaling:asg",
            "OptionName": "MinSize",
            "Value": "1",
        },
        {
            "Namespace": "aws:ec2:vpc",
            "OptionName": "Subnets",
            "Value": "subnet-06d8d87920e940944"
        },
    ],
)

print("Envoirnment Created...")