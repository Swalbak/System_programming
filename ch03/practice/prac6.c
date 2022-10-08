// 6. .과 .. 제외한 디렉토리 내용 출력하기

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main(void){
        char path[BUFSIZ];
        getcwd(path, BUFSIZ);
        DIR *dp;

        if((dp = opendir(path)) == NULL){
                perror("opendir");
                exit(1);
        }
        int i = 0;
        struct dirent *dent;
        while(dent = readdir(dp)){
                if(dent->d_name[0] == '.')
                        continue;
                printf("%s\t", dent->d_name);
                i++;
                if((i%8)==0)
                        printf("\n");
        }

        printf("\n");
        closedir(dp);

        return 0;
}
