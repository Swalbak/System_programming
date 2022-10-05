// 3. lseek 함수를 사용해 데이터 파일을 읽고 아래 출력 형태와 같이 출력하는 프로그램을 작성하라.
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
