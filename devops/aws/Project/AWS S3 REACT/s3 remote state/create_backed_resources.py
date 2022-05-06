# Create S3 Bucket with versioing 
# sse and DynamoDB Table
import boto3
import variables


s3_client = boto3.client('s3',
region_name=variables.REGION,
)

# create s3 bucket
s3_client.create_bucket(Bucket=variables.BUCKET_NAME, 
CreateBucketConfiguration={
        'LocationConstraint': variables.REGION
    },
ACL='private'
)

# enable versioning
s3_client.put_bucket_versioning(Bucket=variables.BUCKET_NAME,
VersioningConfiguration=variables.VERSIONING_POLICY)

# enable SSE Encryption
s3_client.put_bucket_encryption(Bucket=variables.BUCKET_NAME,
ServerSideEncryptionConfiguration=variables.SSE_POLICY)

# block public access
s3_client.put_public_access_block(
    Bucket=variables.BUCKET_NAME,
    PublicAccessBlockConfiguration={
        'BlockPublicAcls': True,
        'IgnorePublicAcls': True,
        'BlockPublicPolicy': True,
        'RestrictPublicBuckets': True
    }
)

# enable only ssl requests
s3_client.put_bucket_policy(Bucket=variables.BUCKET_NAME,
Policy=variables.BUCKET_POLICY)


DynamoDB_client = boto3.client('dynamodb',
region_name=variables.REGION)

# create table
DynamoDB_client.create_table(TableName=variables.TABLE_NAME,
AttributeDefinitions=variables.ATTRIBUTE_DEFINITION,
KeySchema=variables.KEY_SCHEMA,
BillingMode='PAY_PER_REQUEST')