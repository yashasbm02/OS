#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/mman.h>

int main(){
    void *psm;
    char buf[100];
    int shmid1=shm_open("OS123",O_CREAT|O_RDWR,0666);
    ftruncate(shmid1,1024);
    psm=mmap(0,1024,PROT_WRITE,MAP_SHARED,shmid1,0);
    printf("KEY/ID/fd of the shared memory is %d\n",shmid1);
    printf("Shared memory is attached at %p\n",psm);
    printf("Enter some data to write to shared memory\n");
    read(0,buf,10);
    sprintf(psm,"%s",buf);
    return 0;
}