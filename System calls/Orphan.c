#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t my_pid,child_pid,parent_pid;
    child_pid=fork();
    if(child_pid<0){
        printf("Fork failed! exiting\n");
        exit(0);
    }
    if(child_pid==0){
        printf("[CHILD] This is child process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[CHILD] My pid is %d\n",my_pid);
        printf("[CHILD] Parent pid is %d\n",parent_pid);
        printf("[CHILD] Sleeping for 10 seconds\n");
        sleep(10);
        printf("[CHILD] my parent ended.So i am orphan adopted by init process\n");
    }
    else{
        printf("[PARENT] This is parent process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[PARENT] My pid is %d\n",my_pid);
        printf("[PARENT] My parent pid is %d\n",parent_pid);
        printf("Exiting\n");
        exit(0);
    }
    return 0;
    
}