//To print sequence of number pyramid
#include <stdio.h>
int main(){
    int i,j;
    for (i=5;i>0;i--){              //Number of lines in the output and maximum number i
        for (j=0;j<(5-i);j++){      //Printing the blank spaces
        printf ("\t");
        }
        for (j=1;j<(i*2);j++){      //Because we have to print twice, once forward once back

            if (j>i){                     //This is for backward
                printf("%d\t",(i*2)-j);
            }
            else {                        //This is for forward
                printf("%d\t",j);
            }
        }
        printf("\n");                     //Prints newline when done with one pyramid
        }
    int hold=getchar();
    return 0;
}