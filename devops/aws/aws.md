# Table of Contents
- [download](#download)
- [configuration](#configuration)
- [important](#important)
- [commands](#commands)

<br>
<br>

# download
first we need to download the aws cli in order to work with it remotly.  
(make sure you have python installed).  
after you have python just download the pip package like this:
```
pip install awscli --upgrade
```
now you can run programs using `` aws ``.

<br>
<br>

# configuration
to configure the aws cli we need to use an environment variables.  
we need:
- AWS_ACCESS_KEY_ID
- AWS_SECRET_ACCESS_KEY
- AWS_DEFAULT_REGION

after we configure those variables we can start using commands.

or we can run `` aws configure`` and fill all the information there.

<br>
<br>

# important
there is a url that let ec2 instances learn about themself.
the url is: http://169.254.169.254/latest/meta-data (only works form inside ec2).

<br>
<br>


# commands
## iam commands
1. list users
```bash
aws iam list-users
```

## s3 commands
1. upload a file to an s3 bucket
```
aws s3 cp <local_file_path> s3://<bucket_name>/<file_name>
```


