//ex2_2 O_EXCL 플래그 사용하기
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
        int fd = open("unix.txt", O_CREAT | O_EXCL, 0644);
        if(fd == -1){
                perror("EXCL");
                exit(1);
        }
        close(fd);

        return 0;
}
