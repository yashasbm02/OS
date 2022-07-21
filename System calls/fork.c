#include<stdio.h>
#include<unistd.h>

int main(){
    printf("Before fork\n");
    fork();
    printf("After first fork\n");//2^1=2
    fork();
    printf("After second fork\n");//2^2=4
    fork();
    printf("After third fork\n");//2^3=8

}
