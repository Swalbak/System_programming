//8. 현재 디렉토리에 있는 내용을 파일인지 디렉토리인지 구분해 출력

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(void){
        DIR *dp;
        char *path = getcwd(NULL, BUFSIZ);
        if((dp = opendir(path)) == NULL){
                perror("opendir");
                exit(1);
        }

        struct stat sbuf;
        struct dirent *dbuf;
        mode_t mode;

        while((dbuf = readdir(dp)) != NULL){
                stat(dbuf->d_name, &sbuf);
                mode = sbuf.st_mode & S_IFMT;
                if(mode == S_IFDIR)
                        printf("%s: DIR\n", dbuf->d_name);
                else
                        printf("%s: FILE\n", dbuf->d_name);
        }

        closedir(dp);

        return 0;
}
