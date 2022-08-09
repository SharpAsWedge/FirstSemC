//WAP to know if the given three sides form a triangle or not
#include <stdio.h>
#include <conio.h>
int main (){
	int a,b,c;
	printf("Enter the sides of the triangle:");
	scanf("%d %d %d",&a,&b,&c);
	if ((a+b>c) && (a+c>b) && (b+c>a))
	printf("The sides form a triangle");
	else 
	printf("The sides don't form a triangle");
}



