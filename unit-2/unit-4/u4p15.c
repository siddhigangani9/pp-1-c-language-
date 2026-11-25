#include<stdio.h>
#include<conio.h>
void main()
{
    int n,temp,rem,sum=0;
    printf("Enter a number:");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        rem=n%10;
        sum=sum+(rem*rem*rem);
        n=n/10;
    }
    if(temp==sum)
    {
        printf("%d is an Armstrong number",temp);
    }
    else
    {
        printf("%d is not an Armstrong number",temp);
    }
}
