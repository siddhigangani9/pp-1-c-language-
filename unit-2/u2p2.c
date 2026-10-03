#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b,sum,sub,multi;
    printf("--Calculator--");
    printf("\nEnter a number:");
    scanf("%d",&a);
    printf("\nEnter another number:");
    scanf("%d",&b);
    sum=a+b;
    printf("\nsum of %d and %d is %d",a,b,sum);
    sub=a-b;
   printf("\nsubtraction of %d and %d is %d",a,b,sub);
   multi=a*b;
   printf("\nmultiplication of %d and %d is %d",a,b,multi);
    if(b==0){
    printf("\nDivision by zero error");
    }
    else{
     printf("\ndivision of %d and %d is %d",a,b,a/b);
      printf("\nremainder of %d and %d is %d",a,b,a%b);
      }
      getch();
}
