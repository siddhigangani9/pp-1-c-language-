#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b,temp;
    printf("\nEnter a number:");
    scanf("%d",&a);
    printf("\nEnter another number:");
    scanf("%d",&b);
    printf("\nBefore Swapping");
    printf("\nA is %d",a);
    printf("\nB is %d",b);
    temp=a;
    a=b;
    b=temp;
    printf("\nAfter swapping");
    printf("\nA is %d",a);
    printf("\nB is %d",b);
    getch();
}
