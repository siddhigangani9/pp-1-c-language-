#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b;
    printf("Enter a number:");
    scanf("%d",&a);
    printf("Enter a number:");
    scanf("%d",&b);
    printf("Numbers before swap");
    printf("\nA is %d",a);
    printf("\nB is %d",b);
    a=a+b;//10+20=30
    b=a-b;//30-20=10
    a=a-b;//30-10=20
    printf("\nNumbers after swap");
    printf("\nA is %d",a);
    printf("\nB is %d",b);
    getch();
}
