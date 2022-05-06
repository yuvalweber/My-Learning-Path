# AWS S3 REACT
<hr>
1) first create dynamodb table and s3 bucket for terraform state using python script in 's3 remote state'

```
python create_backend_resources
```

2) run ``terraform deploy`` and see how you get s3 website with cloudfront distribution!!