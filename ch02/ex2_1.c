// ex2_1 새 파일 생성하기
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
        int fd = open("unix.txt", O_CREAT, 644);
        if(fd == -1){
                perror("Creat");
                exit(1);
        }
        close(fd);

        return 0;
}
