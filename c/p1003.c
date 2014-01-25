#include <stdio.h>

static int calc(float target) {

    int cards = 0, i;
    float length = 0;

    while (length < target) {
        ++cards;
        length = 0;
        for (i = 1; i <= cards; ++i) {
            length += 1.0 / (i + 1);
        }
    }

    return cards;
}

int main() {
    float target;
    while (scanf("%f", &target) > 0 && target > 0) {
        printf("%d card(s)\n", calc(target));
    }
}
