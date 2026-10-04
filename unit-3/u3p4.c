#include<stdio.h>
#include<conio.h>
void main()
{
	int a;
	printf("Enter a number:");
	scanf("%d",&a);
	if(a%2==0)
	{
		printf("It's even");
	}
	else
	{
		printf("It's odd");
	}
	getch();
}
