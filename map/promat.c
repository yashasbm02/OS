#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main(){
    void *psm;
    char buf[10];
    int shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
    printf("Key of the shared memory: %d\n",shmid);
    psm=shmat(shmid,NULL,0666);
    printf("Memeory attached at %p\n",psm);
    printf("Enter some data to write to shared memory\n");
    read(0,buf,10);
    sprintf(psm,"%s",buf);
    shmdt(psm);
    return 0;
}