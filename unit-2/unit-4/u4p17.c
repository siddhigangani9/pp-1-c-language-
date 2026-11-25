#include<stdio.h>
#include<conio.h>
void main()
{
    int n,i,j,count;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("Prime number up to %d are:",n);
    for(i=1;i<=n;i++)
    {
        count=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                count++;
            }
        }
        if(count==2)
        {
            printf("\n%d",i);
        }
    }
}
