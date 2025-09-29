#include <stdio.h>
#include <math.h>

void primeFactorization(int n) {
    // Special cases
    if (n == 0) {
        printf("0 has no prime factorization\n");
        return;
    }
    if (n == 1) {
        printf("1 has no prime factorization\n");
        return;
    }

    printf("The prime factorization of %d is: ", n);

    // Step 1: factor out 2
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }

    // Step 2: factor odd numbers from 3 to sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }

    // Step 3: if n > 2, then n is prime
    if (n > 2) {
        printf("%d", n);
    }

    printf("\n");
}

int main() {
    int num;
    scanf("%d", &num);
    primeFactorization(num);
    return 0;
}