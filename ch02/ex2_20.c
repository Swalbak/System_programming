// 임시 파일명 만들기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
        char *fname;
        char fntmp[BUFSIZ];
        char fname2[BUFSIZ];
        char template[32];

        fname = tmpnam(NULL);
        printf("1. %s\n", fname);
        tmpnam(fname2);
        printf("%s\n", fname2);

        fname = tempnam(".", "hanbat");
        printf("2. %s\n", fname);

        strcpy(template, "./hanbatXXXXXX");
        fname = mktemp(template);
        printf("3. %s\n", fname);


        return 0;
}
