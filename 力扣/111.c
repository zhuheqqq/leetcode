#include <stdio.h>

int sum(int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += i;
    }
    return result;
}

int main() {
    int number = 10;
    int result = sum(number);
    printf("Sum of numbers up to %d is %d\n", number, result);
    return 0;
}
