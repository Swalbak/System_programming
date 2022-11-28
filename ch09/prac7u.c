#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void){
        int fifo1, fifo2;
        int n, i;
        char buf[BUFSIZ];

        if(mkfifo("FIFO1", 0666) == -1){
                perror("mkfifo");
                exit(1);
        }

        if(mkfifo("FIFO2", 0666) == -1){
                perror("mkfifo");
                exit(1);
        }

        if((fifo1 = open("FIFO1", O_WRONLY)) == -1){
                perror("open");
                exit(1);
        }

        if((fifo2 = open("FIFO2", O_RDONLY)) == -1){
                perror("open");
                exit(1);
        }
        printf("Start Chat(USER1)\n");

        while(1){
                printf("User1: ");

                scanf("%s", buf);

                if(write(fifo1, buf, strlen(buf)) == -1){
                        perror("write");
                        exit(1);
                }

                if((n = read(fifo2, buf, BUFSIZ)) != -1){
                        printf("User2: ");

                        for(i = 0; i < n; i++)
                                printf("%c", buf[i]);
                        printf("\n");
                }
                else{
                        perror("read");
                        exit(1);
                }
        }

        return 0;
}