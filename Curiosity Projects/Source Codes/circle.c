#include <stdio.h>

#define GRAPH 10.0
#define MOE (GRAPH/3)
#define INC 0.5
#define sqr(x) ((x)*(x))

int main(){
    float i,j,r,lhs,rhs;
    r=GRAPH/1.2;

    for (i=-GRAPH;i<GRAPH;i+=INC){

        for (j=-GRAPH;j<GRAPH;j+=INC){

            lhs=sqr(i)+sqr(j);
            rhs=sqr(r);
            if(lhs>(rhs-MOE) && lhs<(rhs+MOE)) printf("%s","X ");
            else printf("%s","  ");
        }
        
        putchar('\n');
    }
    getchar();
    return 0;
}