#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
        if(argc != 2){
                printf("argc: %d\n", argc);
                exit(1);
        }
        int fd;
        if((fd = open(argv[1], O_RDONLY)) == -1){
                perror("open");
                exit(1);
        }
        int n;
        char buf[1];
        int linecount = 1;
        printf("%d ", linecount);
        char str[BUFSIZ];

        while((n = read(fd, buf, 1)) > 0){
                if(buf[0] == '\n'){
                        if((n = read(fd, buf, 1))<=0){
                                printf("\n");
                                break;
                        }
                        else{
                                sprintf(str, "\n%d ", ++linecount);
                                lseek(fd, -1, SEEK_CUR);
                        }
                }
                else
                        sprintf(str, "%c", buf[0]);

                printf("%s", str);
        }
        
        close(fd);
}
