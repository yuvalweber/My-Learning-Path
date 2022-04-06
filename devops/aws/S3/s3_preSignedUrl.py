import boto3
import requests


accessKey = "<censored>"
secret_access_key = "<censored>"
bucketName = "<censored>"

s3_client = boto3.client(
    's3',
    aws_access_key_id=accessKey,
    aws_secret_access_key=secret_access_key)

# generate preSignedUrl
response = s3_client.generate_presigned_post(
    Bucket=bucketName,
    key="FileToUpload.jpg",
    ExpiresIn=60
)

# upload file to preSignedUrl
files = {'file':open('FileToUpload.jpg','rb')}
r = requests.post(response['url'],data=response['fields'],files=files)
print(r.status_code)