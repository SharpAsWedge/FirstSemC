#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define FINAL 20.0

void gap(int);
void zero(int);

int main(){
    float pos=0.0;
    int i=0;
    while (pos<FINAL){
        system("cls");
        gap(i);  puts("          ------------");
        gap(i);  puts("          |     __    | ");
        gap(i);  puts("          |    |  |   |");
        gap(i);  puts("          |    |__|   |");
        gap(i);  puts("-----------           ---------------");
        gap(i);  puts("|     __                      __     |>");
        zero(i);puts("=|____(__)____________________(__)____|");
        puts("***********************************************************************************************************************");
        i++;
        pos+=0.3;
        Sleep(16);
    }
}

void gap(int space){
    for (int i=0;i<=space;i++)printf(" ");
}

void zero(int space){
    if (space<=5){
        for(int i=0;i<space;i++) printf("0");
    }
    else{
        for(int i=0;i<space-5;i++) printf(" ");
        for(int i=0;i<5;i++) printf("0");
    }
}