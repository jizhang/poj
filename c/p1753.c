#include <stdio.h>

int matrix[16], step = 33;

int is_same() {
    int i;
    for (i = 1; i < 16; ++i) {
        if (matrix[0] != matrix[i]) {
            return 0;
        }
    }
    return 1;
}

void flip(int n) {
    matrix[n] = !matrix[n];
    if (n % 4 < 3) {
        matrix[n + 1] = !matrix[n + 1];
    }
    if (n % 4 > 0) {
        matrix[n - 1] = !matrix[n - 1];
    }
    if (n / 4 > 0) {
        matrix[n - 4] = !matrix[n - 4];
    }
    if (n / 4 < 3) {
        matrix[n + 4] = !matrix[n + 4];
    }
}

void dfs(int n, int p) {
    if (is_same()) {
        if (step > p) {
            step = p;
        }
        return;
    }
    if (n > 15) {
        return;
    }
    dfs(n + 1, p);
    flip(n);
    dfs(n + 1, p + 1);
    flip(n);
}

int main() {

    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            matrix[i * 4 + j] = getchar() == 'b' ? 1 : 0;
        }
        getchar();
    }

    dfs(0, 0);
    if (step > 32) {
        printf("Impossible\n");
    } else {
        printf("%d\n", step);
    }

    return 0;
}
