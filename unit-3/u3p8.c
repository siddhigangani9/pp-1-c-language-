#include<stdio.h>
#include<conio.h>
void main()
{
	int year;
	printf("Enter a year:");
	scanf("%d",&year);
	if((year%4==0 && year%100!=0)||(year%400==0))
	{
		printf("It's a leap year");
	}
	else
	{
		printf("It's not a leap year");
	}
	getch();
}
