// 2. 입력받은 파일의 접근 권한을 출력하고, 접근 권한을 변경. 문자 모드 기능 구현(mychmod g+w a.c)

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
        if(argc != 3){
                printf("argc error");
                exit(1);
        }

        mode_t mode;
        switch(argv[1][0]){
                case 'u':
                        mode = S_IRUSR;
                        break;
                case 'g':
                        mode = S_IRGRP;
                        break;
                case 'o':
                        mode = S_IROTH;
                        break;
        }

        if(argv[1][2] == 'w')
                mode = mode >> 1;
        else if(argv[1][2] == 'x')
                mode = mode >> 2;


        struct stat sbuf;
        stat(argv[2], &sbuf);
        mode_t before_mode = sbuf.st_mode;

        if(argv[1][1] == '+')
                sbuf.st_mode |= mode;
        else
                sbuf.st_mode &= ~(mode);

        chmod(argv[2], sbuf.st_mode);
        stat(argv[2], &sbuf);

        char rwx[] = {'r', 'w', 'x'};
        char mode_str[10];
        int count;

        for(count = 0; count<9; count++){
                if((before_mode & (S_IRUSR >> count))!=0)
                        mode_str[count] = rwx[count%3];
                else
                        mode_str[count] = '-';
        }
        mode_str[9] = '\0';
        printf("before: %s\n", mode_str);

        for(count=0; count<9; count++){
                if((sbuf.st_mode & (S_IRUSR >> count)) != 0)
                        mode_str[count] = rwx[count%3];
                else
                        mode_str[count] = '-';
        }
        mode_str[9] = '\0';
        printf("after: %s\n", mode_str);

        return 0;
}
