// 문자 기반 입출력 함수 사용하기
#include <stdio.h>
#include <stdlib.h>

int main(void){
        FILE *rfp, *wfp;
        int c;

        if((rfp = fopen("unix.txt", "r")) == NULL){
                perror("fopen");
                exit(1);
        }

        if((wfp = fopen("unix.bak", "w")) == NULL){
                perror("fopen");
                exit(1);
        }

        while((c = getw(rfp)) != EOF){
                putw(c, wfp);
                printf("%c", c);
        }

        fclose(wfp);
        fclose(rfp);

        return 0;
}
