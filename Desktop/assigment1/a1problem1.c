#include <stdio.h>

int main() {
    char morning, mom, asleep;
    
    // Read inputs
    scanf(" %c", &morning); // 'y' or 'n'
    scanf(" %c", &mom);     // 'y' or 'n'
    scanf(" %c", &asleep);  // 'y' or 'n'
    
    if (asleep == 'y') {
        printf("Don't answer phone\n");
    } else if (morning == 'y' && mom == 'n') {
        printf("Don't answer phone\n");
    } else {
        printf("Answer phone\n");
    }
    
    return 0;
}