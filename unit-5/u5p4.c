#include <stdio.h>


int sumOfDigits(int n) {
    int sum = 0, rem;
    while (n != 0) {
        rem = n % 10;
        sum = sum + rem;
        n = n / 10;
    }
    return sum;
}

int main() {
    int num, result;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    result = sumOfDigits(num);
    printf("Sum of digits = %d\n", result);

    return 0;
}
