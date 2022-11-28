#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void){
        int a;
        pid_t pid;
        int fd[2];
        char *msg;

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
                        execlp("wc", "wc", "-l", (char *)NULL);
                        exit(1);
                        break;
                default:
                        close(fd[0]);
                        msg = "line\n";

                        for(a = 0; a < 100; a++)
                                if(write(fd[1], msg, strlen(msg)) == -1){
                                        perror("write");
                                        exit(1);
                                }

                        close(fd[1]);
                        wait(NULL);
                        break;
        }

        return 0;
}