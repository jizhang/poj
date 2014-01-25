#include <stdio.h>

int main() {
    float i;
    float sum = 0;
    while (scanf("%f", &i) > 0) {
        sum += i;
    }
    printf("$%.2f\n", sum / 12);
    return 0;
}
