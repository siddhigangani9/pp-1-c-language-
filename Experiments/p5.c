#include <stdio.h>
#include <string.h>

// Define a structure to store employee payroll details
struct Employee {
    int id;
    char name[50];
    char designation[50];
    float basicSalary;
    float hra;        // House Rent Allowance (15% of Basic)
    float da;         // Dearness Allowance (20% of Basic)
    float pf;         // Provident Fund (10% of Basic)
    float lic;        // Life Insurance Corporation (8% of Basic)
    float grossSalary;
    float totalDeductions;
    float netSalary;
};

// Function to calculate salary components
void calculateSalary(struct Employee *emp) {
    // Calculate Allowances
    emp->hra = 0.15 * emp->basicSalary;
    emp->da = 0.20 * emp->basicSalary;

    // Calculate Gross Salary = Basic + HRA + DA
    emp->grossSalary = emp->basicSalary + emp->hra + emp->da;

    // Calculate Deductions = PF (10%) + LIC (8%)
    emp->pf = 0.10 * emp->basicSalary;
    emp->lic = 0.08 * emp->basicSalary;
    emp->totalDeductions = emp->pf + emp->lic;

    // Calculate Net Salary = Gross Salary - Total Deductions
    emp->netSalary = emp->grossSalary - emp->totalDeductions;
}

// Function to display individual salary slip
void displayPaySlip(struct Employee emp) {
    printf("\n----------------------------------------\n");
    printf("            EMPLOYEE PAY SLIP           \n");
    printf("----------------------------------------\n");
    printf("Employee ID   : %d\n", emp.id);
    printf("Name          : %s\n", emp.name);
    printf("Designation   : %s\n", emp.designation);
    printf("Basic Salary  : %.2f\n", emp.basicSalary);
    printf("HRA (15%%)     : %.2f\n", emp. hra);
    printf("DA (20%%)      : %.2f\n", emp.da);
    printf("Gross Salary  : %.2f\n", emp.grossSalary);
    printf("PF (10%%)      : %.2f\n", emp.pf);
    printf("LIC (8%%)      : %.2f\n", emp.lic);
    printf("Total Ded.    : %.2f\n", emp.totalDeductions);
    printf("Net Salary    : %.2f\n", emp.netSalary);
    printf("----------------------------------------\n");
}

int main() {
    int n, i;

    printf("Enter the number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    struct Employee emp[n];
    float orgTotalGross = 0, orgTotalNet = 0;

    // Input Employee Details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf(" %[^\n]s", emp[i].name); // Read string with spaces

        printf("Designation: ");
        scanf(" %[^\n]s", emp[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basicSalary);

        // Perform calculations
        calculateSalary(&emp[i]);

        // Accumulate organizational totals
        orgTotalGross += emp[i].grossSalary;
        orgTotalNet += emp[i].netSalary;
    }

    // Generate Individual Salary Slips
    for (i = 0; i < n; i++) {
        displayPaySlip(emp[i]);
    }

    // Generate Organizational Salary Summary
    printf("\n========================================\n");
    printf("      ORGANIZATIONAL SALARY SUMMARY     \n");
    printf("========================================\n");
    printf("Total Employees Processed : %d\n", n);
    printf("Total Gross Payout        : %.2f\n", orgTotalGross);
    printf("Total Net Payout          : %.2f\n", orgTotalNet);
    printf("========================================\n");

    return 0;
}
