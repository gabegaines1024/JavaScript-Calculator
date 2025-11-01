#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Negative numbers not allowed\n");
        return 0;
    }

    if (num == 0) {
        printf("0\n");
        return 0;
    }

    // Print reverse binary directly
    while (num > 0) {
        printf("%d", num % 2); // print remainder (0 or 1)
        num /= 2;              // divide by 2
    }

    printf("\n");
    return 0;
}