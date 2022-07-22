#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFERSIZE 30

int main(){
    int fd,n;
    char buffer[BUFFERSIZE];
    fd=open("m6.c",O_RDWR);
    printf("File descirptor is %d\n",fd);
    if(fd==-1){
        printf("failed to open file\n");
        exit(0);
    }
    printf("Reading first 10 characters from file\n");
    n=read(fd,buffer,10);
    write(1,buffer,n);
    printf("Skipping 5 characters from file\n");
    lseek(fd,5,SEEK_CUR);
    n=read(fd,buffer,10);
    printf("Going 10 characters before the postion in the file\n");
    lseek(fd,-10,SEEK_CUR);
    n=read(fd,buffer,10);
    printf("going to 5th last character in file\n");
    lseek(fd,-5,SEEK_END);
    n=read(fd,buffer,7);
    write(1,buffer,5);
    printf("Going to 3rd chaarcter in the file\n");
    lseek(fd,3,SEEK_SET);
    n=read(fd,buffer,5);
    write(1,buffer,n);
    return 0;
}