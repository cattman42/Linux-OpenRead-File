// Caleb Catt

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
int main(int argc, char** argv){
    int input = open("hello.txt", O_RDWR);
    struct stat myStat = {};
    if(fstat(input, &myStat)){
        printf("Not able to load file info\n");
    }
    off_t size = myStat.st_size;
    char *addr;
    addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, input, 0);
    if(addr == MAP_FAILED){
        printf("mmap error\n");
    }
    if(addr[0] == 'H'){
        addr[0] = 'J';
    }
    else if(addr[0] == 'J'){
        addr[0] = 'H';
    }
    return 0;
}