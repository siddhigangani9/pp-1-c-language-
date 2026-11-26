#include<stdio.h>
int add(int a, int b);
void main()
{
    int num1,num2,sum;
    printf("Enter a number:");
    scanf("%d",&num1);
    printf("Enter a number:");
    scanf("%d",&num2);
    sum=add(num1,num2);
    printf("Sum = %d",sum);
}
int add(int a,int b)
{
    return a+b;

}
