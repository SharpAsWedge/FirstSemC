#include <stdio.h>
void main()
{
int i,j,k;
for(i=0;i<10;i+=2)
{
for(j=10;j>i;j-=2)
{
printf(" ");
}
for(k=0;k<=i;k++)
{
printf("*");
}
printf("\n");
}
int hold = getchar();
}