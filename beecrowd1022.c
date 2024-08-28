#include <stdio.h>

int Gcd(int a, int b);
int Lcm(int a, int b);
void AddFractions(int num1, int den1, int num2, int den2, int *numerator, int *denominator);
void SubtractFractions(int num1, int den1, int num2, int den2, int *numerator, int *denominator);
void MultiplyFractions(int num1, int den1, int num2, int den2, int *numerator, int *denominator);
void DivideFractions(int num1, int den1, int num2, int den2, int *numerator, int *denominator);

int main() {
    char operation;
    int num1, den1, num2, den2;
    int numerator, denominator, gcd;
    int numCases;

    scanf("%d", &numCases);

    while (numCases--) {
        scanf("%d / %d %c %d / %d", &num1, &den1, &operation, &num2, &den2);

        if (operation == '+') {
            AddFractions(num1, den1, num2, den2, &numerator, &denominator);
        } else if (operation == '-') {
            SubtractFractions(num1, den1, num2, den2, &numerator, &denominator);
        } else if (operation == '*') {
            MultiplyFractions(num1, den1, num2, den2, &numerator, &denominator);
        } else if (operation == '/') {
            DivideFractions(num1, den1, num2, den2, &numerator, &denominator);
        }

        gcd = Gcd(numerator, denominator);

        if (gcd < 0) {
            printf("%d/%d = %d/%d\n", numerator, denominator, -(numerator / gcd), -(denominator / gcd));
        } else {
            printf("%d/%d = %d/%d\n", numerator, denominator, numerator / gcd, denominator / gcd);
        }
    }

    return 0;
}

void AddFractions(int num1, int den1, int num2, int den2, int *numerator, int *denominator) {
    *numerator = num1 * den2 + num2 * den1;
    *denominator = den1 * den2;
}

void SubtractFractions(int num1, int den1, int num2, int den2, int *numerator, int *denominator) {
    *numerator = num1 * den2 - num2 * den1;
    *denominator = den1 * den2;
}

void MultiplyFractions(int num1, int den1, int num2, int den2, int *numerator, int *denominator) {
    *numerator = num1 * num2;
    *denominator = den1 * den2;
}

void DivideFractions(int num1, int den1, int num2, int den2, int *numerator, int *denominator) {
    *numerator = num1 * den2;
    *denominator = den1 * num2;
}

int Gcd(int a, int b) {
    int remainder = a % b;
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    return b;
}

int Lcm(int a, int b) {
    return (a / Gcd(a, b)) * b;
}