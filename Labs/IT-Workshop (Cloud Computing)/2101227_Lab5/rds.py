import time
import boto3

rdsClient = boto3.client(
    "rds",
    region_name="us-east-1",
)

response = rdsClient.create_db_instance(
    DBName="vishal",
    DBInstanceIdentifier="vishal",
    AllocatedStorage=5,
    DBInstanceClass="db.t2.micro",
    Engine="MySQL",
    MasterUsername="Vishal",
    MasterUserPassword="password",
    PubliclyAccessible=True,
)


while True:
    response = rdsClient.describe_db_instances(
        DBInstanceIdentifier="vishal",
        MaxRecords=20,
    )
    status = response["DBInstances"][0]["DBInstanceStatus"]
    if status == "available" or status == "AVAILABLE":
        break
    else:
        time.sleep(10)

print(response["DBInstances"][0]["Endpoint"]["Address"])
