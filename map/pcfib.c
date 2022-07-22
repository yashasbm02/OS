#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<sys/mman.h>
int main(int argc,char*argv[]){
    int i;
    pid_t pid;
    int n1,n2,n3;
    const int SIZE =4096;
    int shmid;
    void *psm;
    shmid=shmget((key_t)1122,4096,0666|O_CREAT);
    psm=shmat(shmid,NULL,0666);
    if(argc>1){
        sscanf(argv[1],"%d",&i);
        if(i<1){
            printf("Error input %d",i);
            return 0;
        }
    }
    else{
        return 1;
    }
    pid=fork();
    if(pid==0){
        execlp("./fib","fib",argv[1],NULL);
    }
    else if(pid>0){
        wait(NULL);
        printf("PARENT : child completed\n");
        printf("parent printing\n");
        printf("%s",(char*)psm);
        shmdt(psm);
    }
    return 0;
}