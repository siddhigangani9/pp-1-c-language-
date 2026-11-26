#include <stdio.h>

float areaOfRectangle(float length, float width) {
    return length * width;
}

int main() {
    float l, w, area;
    printf("Enter length of rectangle: ");
    scanf("%f", &l);
    printf("Enter width of rectangle: ");
    scanf("%f", &w);

    area = areaOfRectangle(l, w);
    printf("Area of Rectangle = %.2f\n", area);

    return 0;
}
