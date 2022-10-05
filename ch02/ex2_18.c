// fdopen 함수 사용하기
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
        int fd;
        if((fd = open("unix.txt", O_RDONLY)) == -1){
                perror("read");
                exit(1);
        }

        FILE *fp;
        fp = fdopen(fd, "r");

        char buf[BUFSIZ];
        fgets(buf, BUFSIZ, fp);
        printf("%s\n", buf);

        fclose(fp);
        close(fd);
}
