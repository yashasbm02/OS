#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t my_pid,child_pid,parent_pid;
    int i=10;
    child_pid=fork();
    if(child_pid<0){
        printf("Fork failed,exiting\n");
        exit(0);
    }
    if(child_pid==0){
        printf("[CHILD] This is child process\n");
        printf("[CHILD] my pid is %d\n",my_pid);
        printf("[CHILD] my parent pid is %d\n",parent_pid);
        printf("[CHILD] i=%d",--i);
        printf("[CHILD] child process going to load in another program using execlp syscall\n");
        execlp("/bin/pwd","pwd",NULL);
    }
    else{
        printf("[PARENT] This is parent process\n");
        printf("[PARENT] my pid is %d\n",my_pid);
        printf("[PARENT] my parent pid is %d\n",parent_pid);
        printf("[PARENT] my child's pid is %d\n",child_pid);
        printf("[PARENT] i=%d",++i);
        return 0;
    }
}