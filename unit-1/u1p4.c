#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b,c,sum,avg;
    printf("Enter a number:");
    scanf("%d",&a);
    printf("Enter another number:");
    scanf("%d",&b);
    printf("Enter another number:");
    scanf("%d",&c);
    sum=a+b+c;
    avg=sum/3;
    printf("Average is %d",avg);
    getch();
}
