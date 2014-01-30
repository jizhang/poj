#include <stdio.h>

int main() {
    int m[100][100], n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < i + 1; ++j) {
            scanf("%d", &m[i][j]);
        }
    }
    for (i = n - 2; i > -1; --i) {
        for (j = 0; j < i + 1 ; ++j) {
            if (m[i + 1][j] > m[i + 1][j + 1]) {
                m[i][j] += m[i + 1][j];
            } else {
                m[i][j] += m[i + 1][j + 1];
            }
        }
    }
    printf("%d\n", m[0][0]);
    return 0;
}
