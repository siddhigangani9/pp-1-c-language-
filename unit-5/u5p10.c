#include <stdio.h>
#define PI 3.14

float areaOfCircle(float radius) {
    return PI * radius * radius;
}

int main() {
    float r, area;
    printf("Enter radius of circle: ");
    scanf("%f", &r);

    area = areaOfCircle(r);
    printf("Area of Circle = %.2f\n", area);

    return 0;
}
