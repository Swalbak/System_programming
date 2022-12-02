#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
        pid_t pid;

        switch(pid = fork()){
                case -1:
                        perror("fork");
                        exit(1);
                        break;
                case 0:
                        switch(pid = fork()){
                                case -1:
                                        perror("fork");
                                        exit(1);
                                        break;
                                case 0:
                                        printf("%d's child\n", getppid());
                                        break;
                                default:
                                        printf("child pid: %d, parent: %d\n", pid, getppid());
                                        break;
                                }
                        break;
                default:
                        printf("child pid: %d\n", pid);
                        waitpid(pid, NULL, WCONTINUED);
                        break;
        }

        return 0;
}