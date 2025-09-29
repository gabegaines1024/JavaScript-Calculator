#include <stdio.h>

int main() {
    for (char c1 = 'a'; c1 <= 'z'; c1++) {
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            printf("www.%c%c.com\n", c1, c2);
        }
    }
    return 0;
}