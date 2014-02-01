#include <stdio.h>

static int calc(int n) {
    if (n < 10) {
        return n + n;
    } else if (n < 100) {
        return n + n / 10 + n % 10;
    } else if (n < 1000) {
        return n + n / 100 + n % 100 / 10 + n % 10;
    } else if (n < 10000) {
        return n + n / 1000 + n % 1000 / 100 + n % 100 / 10 + n % 10;
    }
}

int main() {
    int sn[10000], i, j;
    for (i = 0; i < 10000; ++i) {
        sn[i] = 0;
    }

    for (i = 0; i < 10000; ++i) {
        j = calc(i + 1) - 1;
        if (j < 10000) {
            sn[j] = 1;
        }
    }

    for (i = 0; i < 10000; ++i) {
        if (sn[i] == 0) {
            printf("%d\n", i + 1);
        }
    }
    return 0;
}
