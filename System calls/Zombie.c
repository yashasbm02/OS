#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

pid_t my_pid,child_pid,parent_pid;
child_pid = fork();

if(child_pid<0){
    printf("Fork failed,exiting\n");
    exit(0);
}
if(child_pid==0){
    printf("[CHILD] This is child process\n");
    my_pid=getpid();
    parent_pid=getppid();
    printf("[CHILD] my pid is %d\n",my_pid);
    printf("[CHILD] parent pid is %d\n",parent_pid);
    printf("[CHILD] exiting\n");
    exit(0);
}

else{
    printf("[PARENT] this is parent process\n");
    my_pid=getpid();
    parent_pid=getppid();
    printf("[PARENT] my pid is %d\n",my_pid);
    printf("[PARENT] parent pid is %d\n",parent_pid);
    printf("[PARENT] parent sleeping for 10 seconds\n");
    sleep(10);
    printf("[PARENT] child pid= %d has ended,bit it has an entry in process table.It is a zombie process\n",child_pid);
    }
    return 0;
}
