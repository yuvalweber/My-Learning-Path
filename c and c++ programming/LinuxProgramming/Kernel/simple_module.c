#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");


int simple_export_module()
{
    printk(KERN_ALERT "this is exported symbol");
    return 0;
}

EXPORT_SYMBOL(simple_export_module);
// after initialize this variable removes from ram
__initdata int count = 5;

// after initialize this code removes from ram
__init int simple_module_init()
{
    int index = 0;
    for(index = 0; index < count; index++)
    {
        printk(KERN_ALERT "Inside %s function: index -> %d",__FUNCTION__,index);
    }
    
    return 0;
}

int count2 = 2;
/* initialize a parameter you can pass to the module
   the 0644 is file permission of the parameter */
module_param(count2,int,0644);
void simple_module_exit()
{
    int index = 0;
    for(index = 0;index < count2; index++)
    {
        printk(KERN_ALERT "Inside %s function: index -> %d",__FUNCTION__,index);
    }
}

module_init(simple_module_init);
module_exit(simple_module_exit);