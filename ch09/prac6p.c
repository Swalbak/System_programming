#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void){
        int wfd;
        int n;
        int fifo;
        char buf[BUFSIZ];

        printf("Parent process\n");

        if((fifo = open("FIFO", O_RDONLY)) == -1){
                perror("open");
                exit(1);
        }

        if((wfd = open("temp.txt", O_TRUNC | O_CREAT | O_WRONLY, 0644)) == -1){
                perror("open");
                exit(1);
        }

        while((n = read(fifo, buf, BUFSIZ)) > 0)
                if(write(1, buf, n) != n || write(wfd, buf, n) != n){
                        perror("write");
                        exit(1);
                }

        if(n == -1){
                perror("read");
                exit(1);
        }

        close(wfd);
        close(fifo);

        return 0;
}