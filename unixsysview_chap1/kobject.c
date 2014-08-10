

#define to_cdev(ptr_kobj)  container_of(ptr_kobj,cdev,kobj) 

static int __init global_init(){

}

static void __exit global_exit(){

}


module_init(global_init);
module_exit(global_clean);
