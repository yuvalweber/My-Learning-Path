# Table of Contents
- [components](#components)
    * [Deployment config](#deployment-config)
    * [Build Config](#build-config)
    * [Routes](#routes)
    * [Services](#services)
- [strategies](#strategies)
    * [rolling](#rolling)
    * [recreate](#recreate)
    * [custom](#custom)
- [podman commands](#podman-commands)
- [s2i commands](#s2i-commands)
- [skopeo commands](#skopeo-commads)
- [openshift commands](#openshift-commands)

<br>
<br>

# components

## <ins>Deployment config</ins>
Represente set of containers included in a pod and deployment strategies.  
deploy the image on pods and containers and create them,  
 and also rebuild them based on changes.

<br> 

 ## <ins>Build Config</ins>
 Defines a process to be executed in the OpenShift project.  
Used by the OpenShift s2i feature.  
also define how to build the image.

<br>

## <ins>Routes</ins>
Represent a DNS host name recognized by OpenShift router as an ingress
point for applications and microservices.

<br>

## <ins>Services</ins>

1) service in openshift has both name and selector.  
   a service uses its selector to identify pods that should 
   receive application requests.  
   OpenShift applications use the service name to connect to 
   the service endpoints.

2) an application discovers a service using either env variable
   or the OpenShift internal DNS Server.  
   using env var requires the service to be defined before
    the application pod is being created.  
    the dns is more flexiable because it allows to discover dynamically.

<br>
<br>

# strategies
## <ins>rolling</ins>
this is the default strategy.  
It replaces old version instances with new ones.  
Determine when new pods are ready before scaling down older pods.  
If it won't succeedd then it roll back the deployment.

<br>

## <ins>recreate</ins>
stops all currently running pods, and when all stoped it starts the new ones.

<br>

## <ins>custom</ins>
The Custom build strategy allows developers to define a specific builder image responsible for the entire build process.

<br>
<br>

# podman commands

1) pull images  
```
podman pull <image_name>
```

2) running a container  
``` 
podman run <image_name> <command>
```

3) if you want with terminal open and deattach from container run  
```
podman run -dit <image_name> <command>
```

4) define container with environment varriables  
```
podman run -dit -e DANI=DANON -e YAKOV=BETEL <image_name> <command>
```

5) show ip address of container  
```
podman inspect -l -f "{{.NetworkSettings.IPAddress}}"
```

6) run command with newlines
```
podman run --name "dani" -dit -e YAKOV=BETEL \
	<image_name> <command>
```

7) check which container is running  
```
podman ps
```

8) show only values you want for running containers  
```
podman ps --format "{{.ID}} {{.Image}} {{.Names}}"
```

9) execute command on running container   
```
podman exec -it <container_name> <command>
```

10) stop running container  
```
podman stop <conatiner_name>
```

11) force kill container  
```
podman kill <container_name>
```

12) you can choose also which signal to send  
(for example `podman kill -s Core <container_name> ` will produce also core dump)  
```
podman kill -s <signal_name> <conatiner_name>
```


13) restart stopped container  
```
podman restart <container_name>
```

14) delete a container (if specify -f, also stop it ,if it's not stopped)
```
podman rm <container_name> 
```


15) show logs about container  
```
podman logs <container_name>
```

16) apply selinux context to directory  
```
sudo semanage fcontext -a -t cotainer_file_t '/var/dbfiles(/.*)?'
sudo restorecon -Rv /var/dbfiles
```

17) mount a storage using -v  
```
sudo podman run -v <host_folder>:<container_folder> <image_name>
```

18) see port assigned by podman  
```
podman port <container_name>
```

19) save image as .tar file  
```
podman save -o <filename> <image_name>
```

20) load the .tar file  
```
podman load -i <filename>
```

21) delete image  
```
podman rmi <image_name>
```

22) commit an image  
```
podman commit --author "yuval weber" <conatiner> <image>
```

23) commit changes to another image
```
podman commit <base_image> <new_image>
```

24) see what was changed in container states  (A == added, C == changed, D == Deleted)
```
podman diff <container>
```

25) retrieve files and folder connected to container  
```
podman inspect -f "{{range .Mounts}}{{println .Destination}}{{end}}" <container_name>
```

26) tag an image  
```
podman tag <image> <tag_name>
```

27) remove tag  
```
podman tag rmi <image:<tag>>
```

28) push image to registry  
```
podman push <image>
```

29) build image from dockerfile  
```
podman build -t <image_name:tag> <dir_where_dockerfile_is>
```

<br>
<br>

# s2i commands

1) create template files required to create a new s2i builder image  
```
s2i create <image_name> <dir>
```

2) build application container image (simulating openshift s2i)  
```
s2i build <app_src_code> <image> <tag>
--as-dockerfile <output_location>
```

<br>
<br>

# skopeo commands

1) insepect an image  
```
skopeo inspect <path_to_image_remote_reg>
```

2) copy from local to remote  
```
skopeo copy oci:/<path>
docker://<path>
```

<br>
<br>

# openshift commands
1) login  
```
oc login <url>
```

2) create new app definition file  
```
oc new-app <image_name> --as-deployment-config -o yaml
#example
oc new-app --docker-image=registry.com/company/app --name=myapp --as-deployment-config
```

3) create app form s2i  (specifty branch using \<url>#\<branch>)
```
oc new-app --as-deploymeny-config -i <image_stream> <git_server> --name=<app_name>
```

4) delpoys newapp from file  
```
oc new-app --file <file> -p <param=value>
```

5) create app using template file  
```
oc create -f <file>
```

6) process template file  (to override parameters add `-p key=value`)
```
oc porcess -f <file>
```

7) process from the project  
```
oc process <template_name>
```

8) retrieve information about resources   (example: `oc get pods`)
```
oc get <resource_type>
```

9) can also be used to output as yaml like  
```
oc get <Resource_type> <resource_name> -o yaml
```

10) get all to file  
```
oc get -o yaml --export is,bc,dc,svc,route > template.yaml
```

11) get by label  
```
oc get <Resource_type> -l <label>
```

12) wait for resources all to be done  
```
oc get pods -w
```

13) get info about all resources  
```
oc get all
```

14) get image streams  
```
oc get is
```

15) retrieve additional information about resource  
```
oc describe <resource_type> <resource_name>
```

16) create resource from resource definition file  (normally used with `oc get`)
```
oc create 
```


17) edit resource definiton file  
```
oc edit
```

18) delete resource from cluster  
```
oc delete <resource_type> name
```

19) execute command inside a container  
```
oc exec <container_id> <options> <command>
```

20) create new project  
```
oc new-project <name>
```

21) show status of application  
```
oc status
```

22) expose a service to outside  
```
oc expose svc/<name>
```

23) port forward service  
```
oc port-forward <pod_name> <host_port:pod_port>
```

24) delete project   
```
oc delete project <name>
```

25) delete by label  
```
oc delete all -l <label>
```

26) see logs  (can also work on build like: `oc logs build/<app_name>`)
```
oc logs <resource_type>/<svc_name>
```

27) see application builds  
```
oc get builds
```

28) get templates   
```
oc get templates 
```

29) trigger new build  
```
oc start-build <app_name>
```

30) create external service  
```
co create service externalname <myservice> \
	--external-name <svc_name>
```

31) see endpoints resources  
```
oc get endpoints
```

32) open rsh to pod  
```
oc rsh <pod_name> <command>
```

33) start interactive shell  
```
oc rsh -t <pod_name>
```

34) copy file from remote pod (need the tar command in the container)
```
oc cp <pod>:<path_to_file> <local_file_path> 
```

35) adding policy to openshift to allow user running the container to access files  
```
oc adm policy add-scc-to-user anyuid -z default
```

36) remove everything from pods  
```
oc adm prune
```

37) show events  
```
oc get events
```

38) create service account  
```
oc create serviceaccount <name>
```

39) add the user to anyuid SCC   
```
oc adm policy add-scc-to-user anyuid -z <name>
```

40) create config map (you can also use --from-file)
```
oc create configmap <name> --from-literal <key>=<value>
```

41) create secret  
```
oc create secret generic <name> --from-literal <key>=<value>
```

42) create secret for pulling from remote registry  
```
oc create secret generic <name> \
	--from-file .dockerconfigjson=${XDG_RUNTIME_DIR}/containers/auth.json \
	-t kubernets.io/dockerconfigjson
```

43) link the secret to service account  
```
oc secrets link <account> <secret_name>
```

44) import image and create image-stream (if you add `--reference-policy local` then other project who use this).  
image stream could use the secret we defined before
```
oc import-image <image_stream_name> --confirm --from <registry_path>
```

45) grant service account from the expose-image project 
to access image-streams from common project.  
```
oc policy add-role-to-group \
> -n ${RHT_OCP4_DEV_USER}-common system:image-puller \
> system:serviceaccounts:${RHT_OCP4_DEV_USER}-expose-image
```

46) set triggers for build (if you want to remove just add --remove).
```
oc set triggers bc/<name> --from-<github/image/etc>=<image>
```

47) define hook-stop (you can use `--script` instead to specify a script).
```
oc set build-hook bc/name --post-commit \
	--command -- `command` --verbose
```

48) define probes  
```
oc set probe dc/<naem> --<readiness\liveness> <options>
```
<b>Exmple:</b>
```  
oc set probe dc/mayapp --readiness \
	--get-url=http://:8080/healthz --period=20
```

49) rollout to the latest update  
```
oc rollout latest dc/<name>
```

50) see history of rolls (if you want to see about specific deploy user `--revision=<number>`).
```
oc rollout history dc/<name>
```

51) cancel running rollout  
```
oc rollout cancel dc/<name>
```

52) retry failed deployment  
```
oc rollout retry dc/<name>
```

53) rollback (you can add `--to-version`).
```
oc rollback dc/<name>
```

54) scale number of pods in deployment  
```
oc scale dc/name --replicas=3
```

55) inspect imagestream  
```
oc describe istag <name> -n <service>
```