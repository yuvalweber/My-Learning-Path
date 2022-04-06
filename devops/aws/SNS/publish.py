from urllib import response
import boto3
import json

accessKey = "<censored>"
secret_access_key = "<censored>"
topicArn = "<censored>"

snsClient = boto3.client(
    'sns',
    aws_access_key_id=accessKey,
    aws_secret_access_key=secret_access_key,
    region_name='us-east-1')

objectToPublish = {"transactionId":123,"ammount":50}
response = snsClient.publish(
    TopicArn=topicArn,
    Message=json.dumps(objectToPublish),
    Subject='PURCHASE',
    MessageAttributes={ "TransactionType": {"DataType":"String","StringValue":"PURCHASE"}}
)

print(response['ResponseMetadata']['HTTPStatusCode'])