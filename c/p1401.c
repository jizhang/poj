#include <stdio.h>

int calc(int nn) {
    int f = 0;
    while (nn) {
        nn /= 5;
        f += nn;
    }
    return f;
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
