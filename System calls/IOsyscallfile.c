#include<unistd.h>
#include<stdio.h>

#define BUFFERSIZE 30
int main(){
    char buffer[BUFFERSIZE];
    int n;
    printf("Enter string\n");
    n=read(0,buffer,BUFFERSIZE);
    printf("Number of characters read %d\n",n);
    write(1,buffer,n);
    return 0;
}