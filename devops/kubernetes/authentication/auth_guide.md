# Table of Contents
- [Authentication Options](#Authentication-Options)
    * [basic auth file](#basic-auth-file)
    * [token authentication file](#token-authentication-file)
    * [certificate authentication](#certificate-authentication)
        + [using the certificate](#using-the-certificate)
<br>
<br>
<br>

# Authentication Options
## <ins>basic auth file </ins>
you must specify the path to the users.csv file in the kube-api process.

we do it by specifying the ``--basic-auth-file=users.csv`` in the kube-api process.

then we create Role+Binding (like the one we have in our current folder).


and then we authenticate with curl command like that:
```
curl -v -k https://node:6443/api/v1/pods -u "<user>:<password>"
```
<br>
<br>

## <ins> token authentication file </ins>
you must specify the path to the tokens.csv file in the kube-api process.

we do it by specifying the 
``--token-auth-file=tokens.csv`` in the kube-api process.

then we create Role+Binding (like the one we have in our current folder).

and then we authenticate with curl command like that:
```
curl -v -k https://node:6443/api/v1/pods --header "Authorization: Bearer <token>"
```
<br>

## <b style="color:#cdcd57"> The user or the token authentication method are not recommended, and are for educational purposes only!! </b>

<br>
<br>
<br>

## <ins> certificate authentication </ins>
### first we generate certificate for the server.
1) first generate private key with openssl
```
openssl genrsa -out ca.key 2048
```
2) then create csr with the key
```
openssl req -new -key ca.key -subj "/CN=KUBERNETS-CA" -out ca.csr
```
3) then we sign the request
```
openssl x509 -req -in ca.csr -signkey ca.key -out ca.crt
```
4) to show info about the cert run
```
openssl x509 -in <cert> -text -noout
```

### now we generate for client
1) generate admin key with openssl
```
openssl genrsa -out admin.key 2048
```
2) create csr. (we specify system:masters, so that the user will be admin, because its certificate tells that he is part of the administrators groups)
```
openssl req -new -key admin.key -subj "/CN=kube-admin/O=system:masters" -out admin.csr
```
3) sign the certificate with the CA cert
```
openssl x509 -req -in admin.csr -CA ca.crt -CAkey ca.key -out admin.crt
```
you can also use the kubernetes certificate api (see example csr.yml in the current directory).

4) to show info about the cert run
```
openssl x509 -in <cert> -text -noout
```

### <b style="color:#cdcd57"> if we create a certificate for system component like scheduler, we need to add system to its name like that: system:kube-scheduler </b>

<br>
<br>

### <ins>using the certificate</ins>
1) first method is using curl
```
curl https://node:6443/api/v1/pods --key admin.key --cert admin.crt --cacert ca.crt
```
2) using kubeconfig.yml
```
apiVersion: v1
kind: Config
clusters:
- cluster: 
    certificate-authority: ca.crt
    server: https://node:6443
  name: kubernetes
users:
- name: kubernetes-admin
  user:
    client-certificate: admin.crt
    client-key: admin.key
```

