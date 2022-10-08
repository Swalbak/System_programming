// 5. 디렉토리명 인자로 받아 디렉토리 생성, 작업 디렉토리 변경

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]){
        if(mkdir(argv[1], 0755) == -1){
                perror("mkdir");
                exit(1);
        }
        char *path = getcwd(NULL, BUFSIZ);
        printf("before path: %s\n", path);

        chdir(argv[1]);
        path = getcwd(NULL, BUFSIZ);
        printf("after path: %s\n", path);

        return 0;
}
