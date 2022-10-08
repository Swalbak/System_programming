#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
        FILE *rfp;
        if((rfp = fopen(argv[1], "r")) == NULL){
                perror("fopen");
                exit(1);
        }

        char *path = getcwd(NULL, BUFSIZ);
        char *new_path;
        sprintf(new_path, "%s/%s/%s", path, argv[2], argv[1]);
        FILE *wfp;

        if((wfp = fopen(new_path, "w")) == NULL){
                perror("fopen");
                exit(1);
        }
        char str[BUFSIZ];
        while(fgets(str, BUFSIZ, rfp) != NULL)
                fputs(str, wfp);

        sprintf(path, "%s/%s", path, argv[1]);
        unlink(path);
        fclose(wfp);
        fclose(rfp);

        return 0;
}
