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

(you can create static pods by putting a definition file in the StaticPod folder.

you can find out where it is by looking at the config file located in /var/lib/kubelet/config.yaml on the node).

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
kubectl logs <pod_name> <container_name>
```

8) execute command on pod  
```
kuebctl exec <pod_name> <container> -- <command>
```

9) open shell on pod  
```
kubectl exec -ti <pod_name> <container> -- bash
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
kubectl set image deployment/<name> <container_name>=<name_of_new_image>
```

16) check a rollout status
```
kubectl rollout status deployments/<name> 
```

17) check rollout history status
```
kubectl rollout history deployment/<name>
```

18) undo a rollout  
```
kubectl rollout undo deployments/<name>
```

19) output the command to yaml file
```
kubectl run redis --image=redis --dry-run=client -o yaml > definition.yml
```

20) change current working namespace
```
kubectl config set-context $(kubectl config current-context) --namespace=dev
```

21) taint a node
```
kubectl taint nodes <node_name> key=value:NoSchedule
```

22) show all the option for creating a resource
```
kubectl explain pod --recursive | less
```

23) output saved configuration to file
```
kubectl get deployment <example> -o yaml > file.yaml
```
24) create configmap
```
kubectl create configmap <config_name> \
    --from-literal=<key>=<value> \
    --from-literal=<key>=<value>
```
25) create configmap from file
```
kubectl create configmap <config_name> \
    --from-file=<path_to_file>
```
26) create secret 
```
kubectl create secret generic <secret_name> \
    --from-literal=<key>=<value> \
    --from-literal=<key>=<value>
```
27) create secret from file
```
kubectl create secret generic <secret_name> \
    --from-file=<path_to_file>
```
28) show data of secret 
```
kubectl get secret <secret_name> -o yaml
```
29) prepare node for maintenance
```
kubectl drain <node_name>
```
30) move node out of drain, and make it scheduleable.
```
kubectl uncordon <node_name>
```
31) mark node as unscheduleable (but does not terminate and move pods like ``drain``)
```
kubectl cordon <node_name>
```
32) upgrading a cluster
first thing run:
```
kubeadm upgrade plan
```
this will show us information about what version we can upgrade to.
now run
```
kubeadm upgrade apply <version>
```
this will upgrade utilities like apiserver.

for upgrading the ``kubelet`` for example you need to run:
```
apt-get upgrade -y kubelet=<version>
```

now for doing so in each worker node we do this:
1) first we drain the node 
2) we upgrade kubeadm,and kubelet like this:
```
apt-get upgrade -y kubeadm=<version>
```
3) then update the node config:
```
kubeadm upgrade node
```
4) then restart kubelet
```
systemctl restart kubelet
```
5) and now make node scheduleable again 

<br>
<br>

33) create snapshot of etcd
```
ETCDCTL_API=3 etcdctl snapshot save <snapshot_name>.db 
```
34) see info about the snapshot
```
ETCDCTL_API=3 etcdctl snapshot status <snapshot_name>
```
<br>

35) restore from snapshot
1. first stop apiserver
```
systemctl stop kube-apiserver
```
2. then restore
``` 
ETCDCTL_API=3 etcdctl snapshot restore \
<snapshot_name> --data-dir <path>
```
3. reload daemon and restart etcd
```
systemctl daemon-reload
systemctl restart etcd
systemctl restart kube-apiserver
```

36) see available csr
```
kubectl get csr
```

37) approve csr
```
kubectl certificate approve <name>
```

38) deny csr
```
kubectl certificate deny <name>
```

39) delete csr
```
kubectl delete certificate <name>
```

40) show kubernetes config
```
kubectl config show
```
or you can specifiy which config to see
```
kubectl config show --kubeconfig=kubec.config
```

41) change current context
```
kubectl config use-context <context>
```

42) show roles
```
kubectl get roles
```

43) show role bindings
```
kubectl get rolebindings
```

44) show extended info about role
```
kubectl describe role <name>
```

45) check if you have permission to do something.
```
kubectl auth can-i <operation> <resource>
kubectl auth can-i create deployments
# check as another user
kubectl auth can-i <operation> <resource> --as <user> --namespace <namespace>
# check for service account
kubectl auth can-i <operation> <resource> --as system:serviceaccount:<namespace>:<username> --namespace <namespace>
```
46) see namespaced resources
```
kubectl api-resources --namespaced=true
```
47) see unnamespaced resources
```
kubectl api-resources --namespaced=false
```
48) create serviceaccount
```
kubectl create serviceaccount <name>
```
49) see info about serviceaccount
```
kubectl describe serviceaccount <name>
```
50) get pods image with jsonpath
```
kubectl get pods -o=jsonpath='{.items[*].spec.containers[*].image}'
```

51) show cpu usage of each node
```
kubectl get nodes -o=jsonpath='{range .items[*]}{.metadata.name}{"\t"}{.status.capacity.cpu}{"\n"}{end}'
```
52) json path with condition
```
kubectl config view --kubeconfig=my-kube-config -o=jsonpath='{.contexts[?(@.context.user == "aws-user")].name}'
```
53) custom columns
```
kubectl get nodes -o=custom-columns=NODE:.metadata.name,CPU:.status.capacity.cpu
```
54) sort by
```
kubectl get nodes --sort-by=.status.capacity.cpu
```
