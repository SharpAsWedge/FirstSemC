#include <stdio.h>
#include <string.h>

int main(){
    char str[20];
    char n[2];
    fgets(str,20,stdin);
    *n=fgetc(stdin);
    puts(str);
    str[strlen(str)-1]='\0';
    strcat(str,n);
    puts(str);
    if (strcmp("Mycat",str)==0)
        printf("Success");
    else
        printf("Failed");
}