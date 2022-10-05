// 문자열 기반 입출력 함수 사용하기
#include <stdio.h>
#include <stdlib.h>

int main(void){
        FILE *rfp, *wfp;
        char buf[BUFSIZ];

        if((rfp = fopen("unix.txt", "r")) == NULL){
                perror("fopen: unix.txt");
                exit(1);
        }

        if((wfp = fopen("unix.bak", "w")) == NULL){
                perror("fopen: unix.bak");
                exit(1);
        }

        while(fgets(buf, BUFSIZ, rfp) != NULL){
                fputs(buf, wfp);
        }

        fclose(wfp);
        fclose(rfp);
}
