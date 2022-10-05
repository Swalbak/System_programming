#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
        int fd;
        if((fd = open("imsi.txt", O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1){
                perror("open: imsi.txt");
                exit(1);
        }
        char *str;
        str = "20191780 YUK";
        write(fd, str, strlen(str));
        lseek(fd, 0, SEEK_SET);

        int n;
        char buf[BUFSIZ];
        while((n = read(fd, buf, BUFSIZ))>0){
                if(write(1, buf, n)!=n)
                    printf("write error");
        }
        close(fd);
}
