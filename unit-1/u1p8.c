#include<stdio.h>
#include<conio.h>
void main()
{
    int n,next,first=0,i,second=1;
    printf("Enter a number:");
    scanf("%d",&n);
    for(i =1; i <= n; i++){
    next=first+second;;
    first=second;
    second=next;
    printf("\n%d",next);
    }
    getch();
}
