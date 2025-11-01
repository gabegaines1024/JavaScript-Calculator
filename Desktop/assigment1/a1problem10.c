#include <stdio.h>

void encrypt(int digits[4]) {
    // Step 1: (digit + 7) % 10
    for (int i = 0; i < 4; i++) {
        digits[i] = (digits[i] + 7) % 10;
    }

    // Step 2: Swap 1st <-> 3rd, 2nd <-> 4th
    int temp = digits[0];
    digits[0] = digits[2];
    digits[2] = temp;

    temp = digits[1];
    digits[1] = digits[3];
    digits[3] = temp;
}

void decrypt(int digits[4]) {
    // Step 1 (reverse swaps): swap 1st <-> 3rd, 2nd <-> 4th
    int temp = digits[0];
    digits[0] = digits[2];
    digits[2] = temp;

    temp = digits[1];
    digits[1] = digits[3];
    digits[3] = temp;

    // Step 2: Reverse (digit + 7) % 10
    for (int i = 0; i < 4; i++) {
        digits[i] = (digits[i] + 10 - 7) % 10;
    }
}

int main() {
    int num;
    char mode;
    scanf("%4d", &num);   // read 4-digit integer
    scanf(" %c", &mode);  // read 'e' or 'd'

    // Break number into 4 digits
    int digits[4];
    digits[0] = (num / 1000) % 10;
    digits[1] = (num / 100) % 10;
    digits[2] = (num / 10) % 10;
    digits[3] = num % 10;

    if (mode == 'e') {
        encrypt(digits);
        printf("Encrypted number: %d%d%d%d\n", digits[0], digits[1], digits[2], digits[3]);
    } else if (mode == 'd') {
        decrypt(digits);
        printf("Decrypted number: %d%d%d%d\n", digits[0], digits[1], digits[2], digits[3]);
    }

    return 0;
}