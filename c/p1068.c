#include <stdio.h>

void p2w(int n, int p[20], int w[20]) {
    int s[40], i, j, left, flag, wi;

    i = 0;
    for (j = 0; j < n; ++j) {
        left = j == 0 ? p[j] : (p[j] - p[j - 1]);
        while (left--) {
            s[i++] = 0;
        }
        s[i++] = 1;
    }

    wi = 0;
    for (i = 0; i < n * 2; ++i) {
        if (s[i] == 1) {
            left = 0;
            flag = -1;
            for (j = i - 1; j > -1; --j) {
                if (s[j] == 0) {
                    ++flag;
                    ++left;
                } else {
                    --flag;
                }
                if (flag == 0) {
                    w[wi++] = left;
                    break;
                }
            }
        }
    }
}

int main() {

    int t, n, i, j, p[20], w[20];

    scanf("%d", &t);
    for (i = 0; i < t; ++i) {
        scanf("%d", &n);
        for (j = 0; j < n; ++j) {
            scanf("%d", &p[j]);
        }
        p2w(n, p, w);
        for (j = 0; j < n; ++j) {
            printf("%d", w[j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
