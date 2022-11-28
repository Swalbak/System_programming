#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void){
        int n, n2;
        pid_t pid;
        int fd1[2], fd2[2];
        char child[BUFSIZ];
        char parent[BUFSIZ];
        char *msg;

        if(pipe(fd1) == -1 || pipe(fd2) == -1){
                perror("pipe");
                exit(1);
        }

        switch(pid = fork()){
                case -1:
                        perror("fork");
                        exit(1);
                        break;
                case 0:
                        close(fd1[1]);  //write
                        close(fd2[0]);  //read
                        strcpy(child, "At Child Process: ");
                        write(1, child, strlen(child));

                        if((n = read(fd1[0], child, BUFSIZ)) == -1){
                                perror("read");
                                exit(1);
                        }
                        write(1, child, n);

                        strcpy(child, "\"YES\" - from child\n");
                        if(write(fd2[1], child, strlen(child)) == -1){
                                perror("write");
                                exit(1);
                        }
                        close(fd1[0]);
                        close(fd2[1]);
                        break;
                default:
                        close(fd1[0]);
                        close(fd2[1]);
                        strcpy(parent, "\"Are you hungry?\" - from parent\n");
                        if(write(fd1[1], parent, strlen(parent)) == -1){
                                perror("write");
                                exit(1);
                        }

                        if((n2 = read(fd2[0], parent, BUFSIZ)) == -1){
                                perror("read");
                                exit(1);
                        }

                        msg = "At Parent Process: ";
                        write(1, msg, strlen(msg));
                        write(1, parent, n2);

                        close(fd2[0]);
                        close(fd1[1]);
                        wait(NULL);
                        break;
        }
        return 0;
}