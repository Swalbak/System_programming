#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        perror("need 2 args");
        exit(1);
    }

    int fd;
    if((fd = open(argv[1], O_RDONLY)) == -1){
        perror("open");
        exit(1);
    }
    char buf[1];
    int line_no = 0;
    int n;
    printf("%d ", ++line_no);
    while((n = read(fd, buf, 1))>0){
        if(buf[0] == '\n'){
            printf("\n");
            if(read(fd, buf, 1) == 0)
                break;
            lseek(fd, -1, SEEK_CUR);
            printf("%d ", ++line_no);
        }
        else
            printf("%c", buf[0]);
    }
    close(fd);
    
    return 0;
}
