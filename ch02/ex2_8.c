// dup2 함수 사용하기
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
        int fd;

        fd = open("unix.txt", O_RDWR);
        if(fd==-1){
                perror("open");
                exit(1);
        }
        int wfd;
        wfd = open("unix.bak", O_CREAT, 0644);
        if(wfd == -1){
                perror("open");
                exit(1);
        }

        dup2(1, 4);
        int n;
        char buf[256];
        while((n=read(fd, buf, 200))>0){
                if(write(wfd, buf, n)!= n)
                        perror("write");

        if(n==-1){
                perror("read");
        }
        printf("aaaafff");
        close(wfd);
        close(fd);
        }

}
