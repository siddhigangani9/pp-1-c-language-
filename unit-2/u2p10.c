#include<stdio.h>
#include<conio.h>
void main()
{
    float pr,qu,disc,totalbef,discamt,finalamt;
    printf("Enter price:");
    scanf("%f",&pr);
    printf("Enter quantity:");
    scanf("%f",&qu);
    printf("Enter discount percent:");
    scanf("%f",&disc);
    totalbef=pr*qu;
    discamt=(totalbef*disc)/100.0;
    finalamt=totalbef-discamt;
    printf("-------bill------");
    printf("\nTotal amount before %f",totalbef);
    printf("\nDiscount given: %f",discamt);
    printf("\nFinal amount: %f",finalamt);

    getch();
}
