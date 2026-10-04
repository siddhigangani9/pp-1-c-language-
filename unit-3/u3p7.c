#include<stdio.h>
#include<conio.h>
void main()
{
	float price,total_purchase,discount,final_payment;
	int quantity;
	printf("Enter the price:");
	scanf("%f",&price);
	printf("Enter quantity:");
	scanf("%d",&quantity);
	total_purchase=price*quantity;
	if(total_purchase>1000)
	{
		discount=total_purchase*0.15;
	}
	else
	{
	       discount=total_purchase*0.10;
	}
	final_payment=total_purchase-discount;
	printf("\n--- Bill Details ---\n");
	printf("Total purchase amount Rs: %2.f\n",total_purchase);
	printf("Discount applied Rs: %2.f\n",discount);
	printf("Final payment Rs:%2.f\n",final_payment);
	getch();
}
