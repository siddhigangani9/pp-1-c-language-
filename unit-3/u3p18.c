#include<stdio.h>
#include<conio.h>
void main()
{
	int a;
	printf("Enter a number:");
	scanf("%d",&a);
	if(a<0)
	{
		printf("Its a negative number");
	}
	else if(a>0)
	{
		printf("Its a positive number");
	}
	else
	{
		printf("Its a zero");
	}
	getch();
}
