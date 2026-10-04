#include<stdio.h>
#include<conio.h>
void main()
{
	char a[20];
	int eng,maths,sci,hindi,sum,guj,roll_no;
	float perc;
	printf("--Result--");
	printf("\nEnter your name:");
	scanf("%s",&a);
	printf("\nEnter roll no:");
	scanf("%d",&roll_no);
	printf("\nEnter english marks:");
	scanf("%d",&eng);
	printf("\nEnter maths marks:");
	scanf("%d",&maths);
	printf("\nEnter science marks:");
	scanf("%d",&sci);
	printf("\nEnter hindi marks:");
	scanf("%d",&hindi);
	printf("\nEnter gujarati marks:");
	scanf("%d",&guj);
	sum=eng+maths+sci+hindi+guj;
	printf("\nSum of marks are %d",sum);
	perc=sum/5.0;
	printf("\nPercentage scored %f",perc);
	if(perc>=90)
	{
		printf("\nGrade A");
	}
	else if (perc>=80)
	{
		printf("\nGrade B");
	}
	else if (perc>=60)
	{
		printf("\nGrade c");
	}
	else if(perc>=35)
	{
		printf("\nJust pass");
	}
	else
	{
		printf("\nFailed!");
	}
	getch();
}
