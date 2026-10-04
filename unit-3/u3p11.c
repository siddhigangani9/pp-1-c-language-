#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
	char a;
	printf("Enter a character:");
	scanf("%c",&a);
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
	{
		printf("Its a vowel");
	}
	else
	{
		printf("Its not a vowel");
	}
	getch();
}
