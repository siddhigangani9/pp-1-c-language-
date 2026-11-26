#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    double num;
    char str[50];

    printf("Enter a number: ");
    scanf("%lf", &num);
    printf("Square root of %.2lf = %.2lf\n", num, sqrt(num));

    printf("Enter a word: ");
    scanf("%s", str);
    printf("Length of '%s' = %lu\n", str, strlen(str));

    return 0;
}
