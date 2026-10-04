#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b;
	printf("Enter a number:");
	scanf("%d",&a);
	printf("Enter another number:");
	scanf("%d",&b);
	if(a>b)
	{
		printf("A is max");
	}
	else
	{
		printf("b is max");
	}
	getch();
}
