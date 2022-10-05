#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void){
        int fd;
        if((fd = open("imsi.txt", O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1){
                perror("open");
                exit(1);
        }
        FILE *fp;
        fp = fdopen(fd, "r+");
        fputs("20191780", fp);

        fclose(fp);
        close(fd);
}
