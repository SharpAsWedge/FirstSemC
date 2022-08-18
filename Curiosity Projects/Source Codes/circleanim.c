#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define DIST 20
float sq(float a){return a*a;}
void ball(float);
const float acceptance = 1.0;

int main(){
    int travel=0;
    float sq=0.1;
    while (travel<DIST){
        
        for (int i=0;i<=travel;i++){
            printf("\n\n");
        }
        ball(sq);
        for (int i=0;i<=DIST-travel;i+=2){
            printf("\n");
        }
        printf("***************************************************************************");
        sq+=0.05;
        travel++;
        Sleep(200);
        system("cls");
    }
    return 0;
}

void ball(float squish){
    const int r = 2;
    float x,y;
    for(x=-r;x<=r+0.2;x+=squish){
        for(y=-r;y<=r+0.2;y+=0.1){
            if(sq(x)+sq(y)>=sq(r)-acceptance&&sq(x)+sq(y) <=sq(r)+acceptance) printf("x");
            else printf(" ");
        }
        printf("\n");
    }
}