#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
        FILE *fp;
        FILE *rfp;
        char buf[BUFSIZ];

        if(argc != 2){
                printf("arg num not match!!\n");
                exit(1);
        }


        if((fp = popen("more", "w")) == NULL){
                perror("popen");
                exit(1);
        }

        if((rfp = fopen(argv[1], "r")) == NULL){
                perror("fopen");
                exit(1);
        }

        while(fgets(buf, BUFSIZ, rfp) != NULL)
                //fputs(buf, fp);
                fprintf(fp, buf);

        pclose(fp);
        fclose(rfp);

        return 0;
}