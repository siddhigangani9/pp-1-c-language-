#include<stdio.h>
#include<conio.h>
void main()
{
    int n,temp,rem,sum,i;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("Armstrong numbers up to %d are:",n);
    for(i=1;i<=n;i++)
    {
        temp=i;
        sum=0;
        while(temp>0)
        {
            rem=temp%10;
            sum=sum+(rem*rem*rem);
            temp=temp/10;
        }
        if(sum==i)
        {
            printf("\n%d",i);
        }
    }
}
