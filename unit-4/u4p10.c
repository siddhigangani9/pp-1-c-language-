#include<stdio.h>
#include<conio.h>
void main()
{
    int a,n,sum;
    for(a=1;a<=10;a++)
    {
        printf("Enter a number:");
        scanf("%d",&n);
        sum=sum+n;
    }
    printf("%d",sum);
}
