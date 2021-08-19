#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int main() {

    //int k;
    FILE* fp;
    fp = fopen("/home/semih/Workspace/Cprojects/Blowfish/Fruits.txt","r");
    char satir[50];

    if(fp == NULL) {
        puts("Not created");
    }
    else {
        while(!feof(fp)) {
            if(fgets(satir,50,fp)) {
                printf("%s",satir);
            }
        }
    }
    fclose(fp);

    return 0;
}
