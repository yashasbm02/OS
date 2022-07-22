#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
int main(int argc,char*argv[]){
    int k=1,n1,n2,n3;
    char atoi;
    void *psm;
    int shmid=shmget((key_t)1122,4096,0666);
    psm=shmat(shmid,NULL,0666);
    printf("CHILD:\n");
    int i = atoi(argv[1]);
    n1=n2;
    n2=n3;
    sprintf("psm","%d",n1);
    printf("%d",n1);
    sprintf(psm,"%d",n2);
    psm+=strlen(psm);
    printf("%d",n2);
    while(k!=i){
        n3=n1+n2;
        sprintf(psm,"%d",n3);
        n1=n2;
        n2=n3;
        psm+=strlen(psm);
        k++;
    }
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
    }
