#include<stdio.h>
#include<conio.h>
void main()
{
    float amt,interest,years,eq;
    printf("Enter principle amount:");
    scanf("%f",&amt);
    printf("Enter rate of interest:");
    scanf("%f",&interest);
    printf("Enter no of years:");
    scanf("%f",&years);
    eq=(amt*interest*years)/100;
    printf("\nSimple interest is %f",eq);
    getch();
}
