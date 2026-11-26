#include <stdio.h>
#include <math.h>

int isArmstrong(int n) {
    int original = n, digits = 0, sum = 0, rem;

    int temp = n;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp != 0) {
        rem = temp % 10;
        sum += round(pow(rem, digits));
        temp /= 10;
    }

    if (original == sum)
        return 1;
    else
        return 0;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
