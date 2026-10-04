#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b;
	printf("Enter a number:");
	scanf("%d",&a);
	printf("Enter another number:");
	scanf("%d",&b);
	if(a%b==0)
	{
		printf("a is divisible by b");
	}
	else
	{
		printf("a is not divisible by b");
	}
	getch();
}
