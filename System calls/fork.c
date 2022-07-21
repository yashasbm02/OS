#include<stdio.h>
#include<unistd.h>

int main(){
    printf("Before fork\n");
    fork();
    printf("After first fork\n");
    fork();
    printf("After second fork\n");
    fork();
    printf("After third fork\n");

}