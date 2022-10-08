// 입력받은 파일의 접근권한을 출력하고, 접근 원한을 변경하는 프로그램을 작성하라. 숫자 모드 기능 구현(mychmod 0777 a.c)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
        if(argc != 3){
                printf("argc error");
                exit(1);
        }

        struct stat sbuf;
        stat(argv[2], &sbuf);
        char rwx[] = {'r', 'w', 'x'};
        char mode_str[10];
        int count;
        for(count = 0; count<9; count++){
                if(((S_IRUSR >> count) & sbuf.st_mode) != 0)
                        mode_str[count] = rwx[count%3];
                else
                        mode_str[count] = '-';
        }
        mode_str[count] = '\0';
        printf("before: %s\n", mode_str);

        if(strlen(argv[1]) != 4){
                printf("arg error\n");
                exit(1);
        }

        int mode_num[4];
        int i;
        for(i=0; i<4; i++){
                mode_num[i] = argv[1][i] - '0';
        }

        mode_t after_mode = mode_num[3];
        for(i = 2; i>=0; i--){
                after_mode |= (mode_num[i] << (9-3*i));
        }

        chmod(argv[2], (mode_t)(after_mode));
        stat(argv[2], &sbuf);

        for(count = 0; count<9; count++){
                if((sbuf.st_mode & (S_IRUSR >> count)) != 0)
                        mode_str[count] = rwx[count%3];
                else
                        mode_str[count] = '-';
        }
        mode_str[9] = '\0';

        printf("after: %s\n", mode_str);

        return 0;
}
