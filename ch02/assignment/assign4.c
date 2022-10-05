#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
        FILE *fp;
        fp = tmpfile();
        int fd;
        fd = fileno(fp);
        dup2(1, fd);

        fputs("unix system", fp);
        fclose(fp);
        close(fd);
}
