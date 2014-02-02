#include <stdio.h>

int five(n) {
    int f = 0;
    while (n % 5 == 0) {
        ++f;
        n = n / 5;
    }
    return f;
}

int calc(int nn) {
    int i, z = 0;
    for (i = 0; i < nn; ++i) {
        z = z + five(i + 1);
    }
    return z;
}

int main() {
    int n, i, nn;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &nn);
        printf("%d\n", calc(nn));
    }
    return 0;
}
