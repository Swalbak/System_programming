#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
        int fd[2];
        pid_t pid;
        char buf[BUFSIZ];
        int rfd;
        int n;

        if(pipe(fd) == -1){
                perror("pipe");
                exit(1);
        }

        switch(pid = fork()){
                case -1:
                        perror("fork");
                        exit(1);
                        break;
                case 0:
                        close(fd[1]);
                        if(fd[0] != 0){
                                dup2(fd[0], 0);
                                close(fd[0]);
                        }
                        execlp("more", "more", (char *)NULL);
                        exit(1);
                        break;
                default:
                        close(fd[0]);
                        if((rfd = open(argv[1], O_RDONLY)) == -1){
                                perror("open");
                                exit(1);
                        }

                        while((n = read(rfd, buf, BUFSIZ)) > 0)
                                if(write(fd[1], buf, n) != n)
                                        perror("write");

                        if(n == -1){
                                perror("read");
                                exit(1);
                        }
                        close(rfd);
                        close(fd[1]);
                        wait(NULL);
                        break;
        }

        return 0;
}