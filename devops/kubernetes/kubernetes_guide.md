# Table of Contents
- [Components](#components)
    * [Pods](##pods)
    * [Replica Set](#replica-set)
    * [Services](#services)
    * [Replication Controllers](#replication-controllers)
    * [Persistent Volumes](#persistent-volumes)
    * [Persistent Volumes Claims](#persistent-volumes-claims)
    * [ConfigMaps and Secrets](#configmaps-and-secrets)
- [Commands](#commands)

<br>

# components
## <ins>pods</ins>
represent a collection of containers that share resources (ip,storage)  
there are couple of pods inside a node.

<br>

## <ins>Replica Set</ins>
the purpose of replica set is to maintain a stable set of replica pods running at any given time.

<br>

## <ins>Services</ins>
An abstract way to expose an application running on a set of Pods as a network service.

<br>

## <ins>Replication Controllers</ins>
Kubernetes resource that define how pods are replicated into different nodes.

<br>

## <ins>Persistent Volumes</ins>
Storage areas used by Kubernetes pods.

<br>

## <ins>Persistent Volumes Claims</ins>
Represent a request for sotrage by pod.  
(normally connects a persistent volume to a pod).

<br>

## <ins>ConfigMaps and Secrets</ins>
contains set of keys=values that can be used by other resources.  
Centralize configuration values used by several resources.  
Secrets are encoded and restricted to some authorized users.

<br>
<br>

# Commands
1) show info about the cluster   
```
kubectl cluster-info
```

2) show available node  
```
kubectl get nodes
```

3) show replica set  
```
kubectl get rs
```

4) create new deployment  
```
kubectl create deployment <name> \
	--image=<path_to_imag_repo>
```

5) list deployments  
```
kubectl get deployments
```

6) list services  
```
kubectl get services
```

7) list resources  
```
kubectl get
```

8) show detailed info about resource  (pods,dc,bc...)  
```
kubectl describe <resource> 
```

7) show logs  
```
kubectl logs <pod_name>
```

8) execute command on pod  
```
kuebctl exec <pod_name> <command>
```

9) open shell on pod  
```
kubectl exec -ti <pod_name> bash
```

10) creating proxy to our pod  
```
kubectl proxy
```

11) expose service  
```
kubectl expose deplyment/<service_name> --type=<type> --port=<port_number>
```

12) add label to pod  
```
kubectl label pod <pod_name> <key>=<value>
```

13) delete resource  (l == label)
```
kubectl delete <resource_type> -l <key>=<value> 
```

14) scaling deployment to some pods  
```
kubectl scale deployments/<deployment_name> --replicas=<number_of_replicas>
```

15) set the image the pods uses  
```
kubectl set image deployments/<name>=<name_of_new_image>
```

16) check an update  
```
kubectl rollout status deployments/<name> 
```

17) undo an update  
```
kubectl rollout undo deployments/<name>
```

18) output the command to yaml file
```
kubectl run redis --image=redis --dry-run=client -o yaml > definition.yml
```

19) change current working namespace
```
kubectl config set-context $(kubectl config current-context) --namespace=dev
```




