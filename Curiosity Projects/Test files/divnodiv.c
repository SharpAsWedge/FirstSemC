#include <stdio.h>

int main(){
    //Doing division using only + and -
    int a,b,quo=0,rem=0;
    int inv=0;
    int temp;
    scanf("%d%d",&a,&b);
    if (b>a) {
        temp=b;b=a;a=temp;
        inv=1;
    }
    temp=a;

    while (a>=b){
        a-=b;
        quo++;
    }
    rem=a;
    printf("The quotient is: %d and remainder is: %d\n",quo,rem);
    printf("i.e. %d x %d = %d + %d = %d",b,quo,b*quo,rem,temp);
    if (inv==1) printf("\n And you entered the larger number later you sick fuck");
}