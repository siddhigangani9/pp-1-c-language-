#include <stdio.h>

#define PI 3.14
#define SQUARE(x) ((x) * (x))

int main() {
    int num;
    float radius;

    printf("Enter a number to find its square: ");
    scanf("%d", &num);
    printf("Square of %d = %d\n", num, SQUARE(num));

    printf("Enter radius of circle: ");
    scanf("%f", &radius);
    printf("Area of circle = %.2f\n", PI * SQUARE(radius));

    return 0;
}
