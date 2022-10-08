// 4. 디렉토리가 비어 있는지 확인한 후 메세지 출력, 비었다면 디렉토리 삭제

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]){
        DIR *dp;
        struct dirent *dbuf;

        if((dp = opendir(argv[1])) == NULL){
                perror("opendir");
                exit(1);
        }

        while(dbuf = readdir(dp)){
                if(dbuf->d_name[0] == '.')
                        continue;
                else{
                        printf("file exist\n");
                        exit(1);
                }
        }

        rmdir(argv[1]);
        closedir(dp);
        printf("deleted\n");

        return 0;
}
