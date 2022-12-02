#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
        pid_t pid;

        switch(pid = fork()){
                case -1:
                        perror("fork");
                        exit(1);
                        break;
                case 0:
                        printf("child process\n");
                        if(execlp("w", "w", (char *)NULL) == -1){
                                perror("execlp");
                                exit(1);
                        }
                        exit(1);
                        break;
                default:
                        printf("parent process\n");
                        if(execlp("date", "date", (char *)NULL) == -1){
                                perror("execlp");
                                exit(1);
                        }
                        exit(1);
                        break;
        }

        return 0;
}