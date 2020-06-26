#include<linux/init.h>
#include<linux/module.h>

int my_init(void){
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);

	return 0;

}

void my_exit(void)
{
	printk(KERN_ALERT "Inside %s function\n", __FUNCTION__);

}

module_init(my_init);
module_exit(my_exit);
