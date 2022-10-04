#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void){
        FILE *fp;

        if((fp = fopen("prac3.dat", "r")) == NULL){
                perror("fopen:prac3.dat");
                exit(1);
        }

        char buf[BUFSIZ];
        int n;
        FILE *wfp;
        if((wfp = fopen("prac4.res", "w")) == NULL){
                perror("fopen");
                exit(1);
        }

        while((n = fread(buf, sizeof(char)*2, 1, fp))>0){   // 2byte씩 읽어온 버퍼에서 1byte씩 읽어서 출력(2byte 한 개씩 읽어옴)
                fwrite(buf, sizeof(char), n, wfp);
        }
        fclose(wfp);
        fclose(fp);
}
