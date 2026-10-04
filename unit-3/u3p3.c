#include<stdio.h>
#include<conio.h>
void main()
{
	int a;
	printf("Enter your age:");
	scanf("%d",&a);
	if(a>=18)
	{
		printf("You're eligible to vote");
	}
	else
	{
		printf("you're not eligible to vote");
	}
	getch();
}
