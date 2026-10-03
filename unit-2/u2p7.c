#include<stdio.h>
#include<conio.h>
void main()
{
    int a,sq,cu;
    printf("Enter a number:");
    scanf("%d",&a);
    sq=a*a;
    cu=a*a*a;
    printf("\nSquare of %d is %d",a,sq);
    printf("\nCube of %d is %d",a,cu);
    getch();
}
