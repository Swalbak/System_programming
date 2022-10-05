// 2. 저수준 파일 입출력을 이용해 파일을 복사하는 프로그램을 작성하라. 파일명은 명령행 인자로 받는다.
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
        if(argc != 3){
                perror("error");
                exit(1);
        }
        int rfd, wfd;
        if((rfd = open(argv[1], O_RDONLY)) == -1){
                perror("open");
                exit(1);
        }
        if((wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1){
                perror("open");
                exit(1);
        }
        int n;
        char buf[BUFSIZ];
        while((n = read(rfd, buf, BUFSIZ))>0){
                if(write(wfd, buf, n) != n)
                        perror("write");
        }

        close(wfd);
        close(rfd);
}
