# commands
1) install a package
```bash
helm install <package>
```
2) upgrade a packge
```bash
helm upgrade <package>
```
3) rollback a package
```bash
helm rollback <package>
```
4) uninstall a package
```bash
helm uninstall <package>
```
5) search for an helm chart
```bash
helm search hub <package>
```
6) add helm repository
```bash
helm repo add <repo_name> <url_for_repo>
```
7) search in the repo
```bash
helm search repo <package>
```
8) list repositories
```bash
helm repo list
```
9) list installed packages
```bash
helm list
```
10) download helm chart without installing
```bash
helm pull --untar <repo>/<package>
```