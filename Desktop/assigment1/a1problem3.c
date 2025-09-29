#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    char op;

    if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
        printf("Error: invalid input\n");
        return 1;
    }

    double result;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                printf("Error: dividing by zero\n");
                return 1;
            }
            result = a / b;
            break;
        case '%':
            if ((int)b == 0) {
                printf("Error: dividing by zero\n");
                return 1;
            }
            result = (int)a % (int)b;
            break;
        case '^':
            result = pow(a, b);
            break;
        case 'r':
            if (a == 0) {
                printf("Error: dividing by zero\n");
                return 1;
            }
            result = pow(b, 1.0 / a);
            break;
        default:
            printf("Error: invalid operator\n");
            return 1;
    }

    printf("%.2lf\n", result);
    return 0;
}