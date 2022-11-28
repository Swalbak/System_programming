#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
        int rfd;
        int pipe;
        int n;
        char buf[BUFSIZ];

        printf("Client\n");

        if(argc != 2){
                perror("args not match");
                exit(1);
        }

        if(mkfifo("FIFO", 0666) == -1){
                perror("mkfifo");
                exit(1);
        }

        if((rfd = open(argv[1], O_RDONLY)) == -1){
                perror("open");
                exit(1);
        }

        if((pipe = open("FIFO", O_WRONLY)) == -1){
                perror("FIFO open");
                exit(1);
        }

        while((n = read(rfd, buf, BUFSIZ)) > 0)
                if(write(pipe, buf, n) != n){
                        perror("write");
                        exit(1);
                }

        close(pipe);
        close(rfd);

        return 0;
}