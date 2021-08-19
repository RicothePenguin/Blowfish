#include <stdio.h>
#include <inttypes.h>
#include <uchar.h>

uint32_t P[8];
uint32_t S[4][256];

void swap(uint32_t a,uint32_t b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
uint32_t f (uint32_t x) {
    uint32_t h = S[0][x >> 24] + S[1][x >> 16 & 0xff];
    return ( h ^ S[2][x >> 8 & 0xff] ) + S[3][x & 0xff];
}
void encrypt(uint32_t *L,uint32_t *R,int x) {
    for(int i=0; i < 6; i++) {
        *L = *L ^ P[i];
        *R = f(*L) ^ *R;
        swap(L,R);
    }
    swap(L,R);
    *L = *L ^ P[8];
    *R = *R ^ P[7];
}
int main() {
    char *ctr;
    int i,j=0;
    FILE *fp,*fs;

    fp = fopen("Fruits.txt","r");
    fs = fopen("temporary.txt","w");

    if(fp == NULL) {

        printf("File does not exists.");
    }
    if(fs == NULL) {
        printf("Could not create the file.");
    }
    printf("Please enter your password : ");

    for(i=0; i < 8; i++) {
        scanf("%lu",&(unsigned long)P[i]);
    }
    char32_t l = 0x00, r = 0x00;

    while(!feof(fp)) {
        j++;
    }
    fgets(ctr,j,fp);

    for(i=0; i <= j/2; i++) {
        char32_t l = *ctr;
        ctr++;
    }
    for(i=j/2; i <= j; i++) {
        char32_t r = *ctr;
        ctr++;
    }









    return 0;
}

