//calder birdsey
//cs315 systems programming 
//assignment 4: self-linker

#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <gnu/lib-names.h>

extern void *_GLOBAL_OFFSET_TABLE_;

int
main(int argc, char *argv[]) {
    //open shared object 
    void *handle; 
    handle = dlopen(LIBC_SO, RTLD_LAZY); 
    if(!handle) {
        fprintf(stderr, "%s\n", dlerror()); 
        return 0; 
    }
    
    //clear existing errors
    dlerror(); 

    //get address of function strcpy 
    void * (*func_addr); 
    * (void **)(&func_addr) = dlsym(handle, "strcpy");
    if(!func_addr) {
        fprintf(stderr, "%s\n", dlerror()); 
        return 0; 
    } 

    //input into global offset table 
    void * GOT_FUNC = ((&_GLOBAL_OFFSET_TABLE_) + 3);
    /*GOT entry for strcopy is always 24 bytes from &_GLOBAL_OFFSET_TABLE_; 
    therefore adding 3-- (3*8 = 24)*/
    *(void **)GOT_FUNC = func_addr; 

    //function call
    char buf[200]; 
    char string[] = "this is a string"; 
    strcpy(buf, string); 
    printf("%s\n", buf); 

    //close shared object 
    dlclose(handle); 
}