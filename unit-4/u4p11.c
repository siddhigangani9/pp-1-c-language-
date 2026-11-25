#include<stdio.h>
#include<conio.h>
void main()
{
    int x,y,i,result=1;
    printf("Enter a number:");
    scanf("%d",&x);
    printf("Enter a number:");
    scanf("%d",&y);
    for(i=1;i<=y;i++)
    {
        result=result*x;
    }
    printf("%d ^ %d = %d",x,y,result);
}
