#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
	char a;
	printf("Enter a character:");
	scanf("%c",&a);
	if(isupper(a))
	{
		printf("It's upper case");
		printf("\n%c",tolower(a));
	}
	else if(islower(a))
	{
		printf("It's lower case");
		printf("\n%c",toupper(a));
	}
	else{
		printf("its digit or special character");
	}
	getch();
}
