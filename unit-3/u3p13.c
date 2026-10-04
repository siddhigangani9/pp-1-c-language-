#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
	int a,b,c;
	printf("Enter a number:");
	scanf("%d",&a);
	printf("Enter another number:");
	scanf("%d",&b);
	printf("Enter another number:");
	scanf("%d",&c);
	if(a<b)
	{
		if(a<c)
		{
			printf("A is min");
		}
		else
		{
			printf("C is min");
		}}
	else{
		if(b<c)
		{
			printf("B is min");
		}
		else
		{
			printf("C is min");
		}
		}
	getch();
}
