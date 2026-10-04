#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
	char a;
	printf("Enter a character:");
	scanf("%c",&a);
	if(a>='A' && a<='Z')
	{
		printf("Its a upper case");
	}
	else if(a>='a'&&a<='z')
	{
		printf("Its a lower case");
	}
	else
	{
		printf("Its a digit or special character");
	}
	getch();
}
