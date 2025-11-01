#include <stdio.h>

void FizzBuzz(int n) {
    if (n % 3 == 0 && n % 5 == 0) {
        printf("Fizz-Buzz");
    } else if (n % 3 == 0) {
        printf("Fizz");
    } else if (n % 5 == 0) {
        printf("Buzz");
    } else {
        printf("%d", n);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Cannot compute Fizz Buzz of %d\n", n);
        return 0;
    }

    int count = 0; // track how many printed per line
    for (int i = n; i >= 1; i--) {
        FizzBuzz(i);
        count++;
        
        if (count == 4 || i == 1) { 
            // after 4 items OR last number, break line
            printf("\n");
            count = 0;
        } else {
            printf(" ");
        }
    }

    return 0;
}