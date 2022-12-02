#include <stdio.h>
#include <stdlib.h>

int main(void){
        if(system("w") == -1){
                perror("system");
                exit(1);
        }

        return 0;
}