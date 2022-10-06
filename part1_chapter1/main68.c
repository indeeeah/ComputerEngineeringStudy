#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    char s[20] = "hello world";
    FILE *fp;
    fp = fopen("temp.txt", "w");
    fprintf(fp, "%s\n", s);
    fclose(fp);
    return 0;
}