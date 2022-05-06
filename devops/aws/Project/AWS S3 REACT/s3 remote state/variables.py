import json
# S3 RELEVANT VARS

REGION="eu-central-1"

BUCKET_NAME="s3-terraform-state-yuval"

VERSIONING_POLICY={
  'MFADelete': 'Disabled',
  'Status': 'Enabled'
}

SSE_POLICY={
  "Rules": [
    {
      "ApplyServerSideEncryptionByDefault": 
      {
        "SSEAlgorithm": "AES256"
      }
    }
  ]
}

BUKCET_POLICY = {
  "Id": "Allow Only SSL",
  "Version": "2012-10-17",
  "Statement": [
    {
      "Sid": "AllowSSLRequestsOnly",
      "Action": "s3:*",
      "Effect": "Deny",
      "Resource": [
        f"arn:aws:s3:::{BUCKET_NAME}",
        f"arn:aws:s3:::{BUCKET_NAME}/*"
      ],
      "Condition": {
        "Bool": {
          "aws:SecureTransport": "false"
        }
      },
      "Principal": "*"
    }
  ]
}

BUCKET_POLICY=json.dumps(BUKCET_POLICY)

# DynamoDB Variables
TABLE_NAME='terraform-tfstate'
ATTRIBUTE_DEFINITION=[
        {
            'AttributeName': 'LockID',
            'AttributeType': 'S'
        },
]
KEY_SCHEMA=[
        {
            'AttributeName': 'LockID',
            'KeyType': 'HASH'
        },
]