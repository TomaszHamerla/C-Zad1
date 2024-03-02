#include <stdio.h>

int sum_of_multiples(int n) {
    if (n < 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int number = 10;
    int result = sum_of_multiples(number);
    printf("Suma wielokrotności 3 lub 5 poniżej %d wynosi %d\n", number, result);
    return 0;
}
