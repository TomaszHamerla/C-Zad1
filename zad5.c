#include <stdio.h>

int sumOfMultiples(int number) {
    if (number < 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < number; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    printf("%d", sumOfMultiples(10));
    return 0;
}