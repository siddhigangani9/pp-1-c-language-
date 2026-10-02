#include<stdio.h>
#include<conio.h>
void main()
{
    int a,sq,cu;
    printf("Enter a number:");
    scanf("%d",&a);
    sq=a*a;
    cu=a*a*a;
    printf("\nsquare of %d is %d",a,sq);
    printf("\ncube of %d is %d",a,cu);
    getch();
}
