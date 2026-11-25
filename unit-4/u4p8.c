#include<stdio.h>
#include<conio.h>
void main()
{
    int i=0,n,a=0,b=1,next;
    printf("enter a number:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("%d\n",a);
        next=a+b;
        a=b;
        b=next;
    }
}
