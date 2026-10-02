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
    a=a+b;//5+4=9
    b=a-b;//9-4=5
    a=a-b;//9-5=4
    printf("\nNumbers after swap");
    printf("\nA is %d",a);
    printf("\nB is %d",b);
    getch();
}
