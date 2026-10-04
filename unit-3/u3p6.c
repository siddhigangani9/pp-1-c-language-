#include<stdio.h>
#include<conio.h>
void main()
{
	float basic_salary,hr,ta,da,pf,gross_salary;
	printf("Enter the basic salary:");
	scanf("%f",&basic_salary);
	if(basic_salary>=5000.0)
	{
		hr=0.05*basic_salary;
		ta=0.06*basic_salary;
		da=0.04*basic_salary;
		pf=0.05*basic_salary;
	}
	else
	{
		hr=0.04*basic_salary;
		ta=0.05*basic_salary;
		da=0.03*basic_salary;
		pf=0.04*basic_salary;
	}
	gross_salary=basic_salary+hr+ta+da-pf;
	printf("\n-- salary Details ---\n");
    printf("hr: %.2f\n", hr);
	printf("ta: %.2f\n", ta);
	printf("da: %.2f\n", da);
	printf("pf: %.2f\n", pf);
	printf("Gross salary: %.2f\n", gross_salary);
	getch();
}
