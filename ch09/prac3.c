#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void){
        int fd[2];
        pid_t pid;
        char *msg;
        char buf[BUFSIZ];
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
                        close(fd[0]);
                        msg = "\"Hello, Parent! - from Child\"\n";
                        if(write(fd[1], msg, strlen(msg)) == -1){
                                perror("write");
                                exit(1);
                        }
                        close(fd[1]);
                        break;
                default:
                        close(fd[1]);
                        strcpy(buf, "Parent: ");
                        write(1, buf, strlen(buf));

                        if((n = read(fd[0], buf, BUFSIZ)) == -1){
                                perror("read");
                                exit(1);
                        }
                        write(1, buf, n);
                        close(fd[0]);
                        wait(NULL);
                        break;
        }

        return 0;
}
