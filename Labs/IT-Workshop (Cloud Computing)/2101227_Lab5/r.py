import boto3

# Create an RDS client
rds_client = boto3.client('rds')

# Define RDS instance details
db_instance_identifier = 'your-db-instance-id'
db_instance_class = 'db.t2.micro'
engine = 'mysql'  # or 'mysql'
master_username = 'admin'
master_password = 'password'
db_name = 'contact_form'

# Create the RDS instance
rds_client.create_db_instance(
    DBInstanceIdentifier=db_instance_identifier,
    AllocatedStorage=20,
    DBInstanceClass=db_instance_class,
    Engine=engine,
    MasterUsername=master_username,
    MasterUserPassword=master_password,
    DBName=db_name,
)


