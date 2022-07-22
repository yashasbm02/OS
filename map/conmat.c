#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

int main(){
    void *psm;
    char buf[10];
    int shmid=shmget((key_t)1122,1024,0666);
    printf("Key of the shared memeory %d\n",shmid);
    psm=shmat(shmid,NULL,0666);
    printf("Memory shared at %p\n",psm);
    printf("data read from shared memory %s",(char*)psm);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}