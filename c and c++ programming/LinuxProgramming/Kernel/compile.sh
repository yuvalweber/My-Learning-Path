make -C /lib/modules/$(uname -r)/build M=$PWD modules

# then in order to run just do `insmode simple_module.ko`
# if you want to pass the param do `insomd simple_module.ko count2=7`  