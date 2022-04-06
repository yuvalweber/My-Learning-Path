# Table of Contents
- [files](#files)
- [commands](#commands)

<hr>

## <ins>files</ins>

1. <b> main.tf </b> - contains definition of resources to build.

2. <b> variables.tf </b> - contains variables definition and default values.

3. <b> terraform.tfvars </b> - contains variables values (you can edit).

4. <b> output.tf </b> - contains variables that you want to show to the screen (it will output them after using the ``apply`` method or by running ``terraform output``).

5. <b> terraform.tfstate </b> - contains the current infrastructure state.

6. <b> terraform.tfstate.backup </b> - contains the older infrastructure state.

7. <b> provider.tf </b> - used to specify specific versions and sources for providers to use.

<hr>

## <ins>commands</ins>
1) initalize environment and download necessary files
```bash
terraform init
```

2) show the execution plan (what will be added and remove)
```bash
terraform plan
```
you can also output the plan to file using ``-out <file_name>``

3) apply the terraform plan
```bash
terraform apply
```
4) use variables with terraform apply
```bash
terraform apply -var "<var>=<value>"
```
5) set variables using environment variables
```bash
export TF_VAR_<VAR_NAME>="VALUE"
```

6) terraform apply with var files with different name
```bash
terraform apply -var-file <file_name>
```

7) destory the infrastructure you created
```bash
terraform destory
```

8) show attributes values
```bash
terraform show
```
or if you want to show it in json format
```bash
terraform show -json
```

9) print output variables 
```bash
terraform output
```
or print only specific variable
```bash
terraform output <var_name>
```

10) check configuration file 
```bash
terraform validate
```

11) format configuration files to make them more readable
```bash
terraform fmt
```

12) see all providers used in the configuration files
```bash
terraform providers
```

13) copy providers to another directory
```bash
terraform providers mirror <another_directory_path>
```

14) sync terraform state with the ``REAL WORLD`` infrastructure state
```bash
terraform refresh
```
(this also run in the background when running ``terraform plan`` or ``terraform apply``)

15) create terraform dependency graph.
```bash
terraform graph
```
(you can use this to see the dependency of your resources)