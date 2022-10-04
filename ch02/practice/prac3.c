#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void){
        int fd;
        if((fd = open("prac3.dat", O_RDONLY)) == -1){
                perror("open");
                exit(1);
        }

        char buf[1];
        int n;
        while((n = read(fd, buf, 1))>0){
                if(write(1, buf, n) != n)
                    perror("write");
                lseek(fd, 1, SEEK_CUR);
        }
        close(fd);

        return 0;
}
