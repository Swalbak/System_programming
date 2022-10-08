// 7. 현재 디렉토리의 파일을 지정한 디렉토리로 이동시키는 프로그램(저수준 입출력 사용하면 오류남)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
        if(argc != 3){
                printf("argc error");
                exit(1);
        }
        char *path = getcwd(NULL, BUFSIZ);
        FILE *fp;

        if((fp = fopen(argv[1], "r")) == NULL){
                perror("fopen");
                exit(1);
        }

        if(chdir(argv[2])==-1){
                perror("chdir error");
                exit(1);
        }

        FILE *wfp;
        if((wfp = fopen(argv[1], "w")) == NULL){
                perror("open");
                exit(1);
        }

        int n;
        char buf[BUFSIZ];
        while((n = fread(buf, sizeof(char), BUFSIZ, fp))>0){
                if(fwrite(buf, sizeof(char), n, wfp) != n)
                        perror("write");
        }
        sprintf(path, "%s/%s", path, argv[1]);
        unlink(path);
        fclose(wfp);
        fclose(fp);

        return 0;
}
