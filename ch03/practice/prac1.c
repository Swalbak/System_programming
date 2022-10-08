// 1. 파일의 정보를 추출하는 프로그램을 작성. 명령행 인자로 파일명 받기.

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
        if(argc != 2){
                printf("not match arg count");
                exit(1);
        }
        struct stat sbuf;
        stat(argv[1], &sbuf);

        int count = 0;
        char mode[10];
        char mode_kind[] = {'r', 'w', 'x'};

        while(count < 9){
                if((sbuf.st_mode & (S_IREAD >> count))!=0)
                        mode[count] = mode_kind[count % 3];
                else
                        mode[count] = '-';
                count++;
        }
        mode[count] = '\0';

        char *file_kind;
        switch(sbuf.st_mode & S_IFMT){
                case S_IFIFO:
                        file_kind = "FIFO";
                        break;
                case S_IFCHR:
                        file_kind = "CHR FILE";
                        break;
                case S_IFDIR:
                        file_kind = "Directory";
                        break;
                case S_IFBLK:
                        file_kind = "Block File";
                        break;
                case S_IFREG:
                        file_kind = "General File";
                        break;
                case S_IFLNK:
                        file_kind = "Symbolic File";
                        break;
                case S_IFSOCK:
                        file_kind = "Socket File";
                        break;
                }

        printf("File Name: %s\n", argv[1]);
        printf("Inode: %d\n", (int)sbuf.st_ino);
        printf("File kind: %s\n", file_kind);
        printf("Permission: %s\n", mode);
        printf("UID: %d\n", (int)sbuf.st_uid);
        printf("Mtime: %d\n", (int)sbuf.st_mtime);

        return 0;
}
