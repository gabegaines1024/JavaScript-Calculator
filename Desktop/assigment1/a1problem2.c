#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Check validity
    if (a <= 0 || b <= 0 || c <= 0 || (a + b + c != 180)) {
        printf("Invalid\n");
        return 0;
    }

    printf("valid"); // always print valid first

    // Check triangle type
    if (a < 90 && b < 90 && c < 90) {
        printf(" acute");
    } else if (a == 90 || b == 90 || c == 90) {
        printf(" right");
    } else if (a > 90 || b > 90 || c > 90) {
        printf(" obtuse");
    }

    // Check isosceles
    if (a == b || b == c || a == c) {
        printf(" isosceles");
        // Check equilateral only if isosceles
        if (a == 60 && b == 60 && c == 60) {
            printf(" equilateral");
        }
    }

    printf("\n");
    return 0;
}