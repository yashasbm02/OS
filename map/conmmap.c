#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main(){
    void *psm;
    char buf[100];
    int shmid=shm_open("OS123",O_RDONLY,0666);
    ftruncate(shmid,1024);
    psm=mmap(0,1024,PROT_READ,MAP_SHARED,shmid,0);
    printf("KEY/ID/fd is %d",shmid);
    printf("shared memeory of the consumer is attached at %p",psm);
    printf("%s",(char*)psm);
    printf("/n");
    shm_unlink("OS123");
    return 0;
}
