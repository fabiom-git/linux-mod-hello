/*
 * Linux modules
 * - 'hello world' module
 * 
 * from the book 'Linux Device Drivers' 
 * 
 * FabioM-2013
 * 
 * */
 
#include <linux/init.h>
#include <linux/module.h>


MODULE_LICENSE("Dual BSD/GPL"); // free licence
MODULE_AUTHOR("FabioMesiti");
MODULE_DESCRIPTION("Nothing to do!");
// MODULE_VERSION("0.1");
// MODULE_ALIAS
 
 
// module loaded
static int hello_init(void)
{
	// message for  /var/log/messages or with 'dmesg' 
	printk(KERN_ALERT "mod_hello: Hello, world\n");
	
	// printk comes from the kernel
	
	return 0;
}

// module unloaded
static void hello_exit(void)
{
	printk(KERN_ALERT "mod_hello: Goodbye, cruel world\n");
	
	// Here, it is important to UNLOAD the resources initiated
	// in the initialization
}

// kernel macros to set init/exit function
module_init(hello_init);
module_exit(hello_exit);
