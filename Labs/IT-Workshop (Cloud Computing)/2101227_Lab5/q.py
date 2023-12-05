import boto3

# Create an RDS client
rds_client = boto3.client('rds')

# Define RDS instance details
instance_name = 'portfolio'
db_instance_identifier = 'portfolio-db-identifier'
db_name = 'contact_form'
master_username = 'Vishal'
master_password = 'password'
instance_class = 'db.t2.micro'  # Choose an appropriate instance type
allocated_storage = 20  # GB

# Create the RDS instance
rds_client.create_db_instance(
    DBInstanceIdentifier=db_instance_identifier,
    DBInstanceClass=instance_class,
    AllocatedStorage=allocated_storage,
    Engine='mysql',  # or 'mysql' for MySQL
    MasterUsername=master_username,
    MasterUserPassword=master_password,
    DBName=db_name,
)

# Wait for the RDS instance to be available
waiter = rds_client.get_waiter('db_instance_available')
waiter.wait(DBInstanceIdentifier=db_instance_identifier)

print(f'RDS instance {db_instance_identifier} is available.')
