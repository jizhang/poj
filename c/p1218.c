#include <stdio.h>

static int calc(int num_cells) {
    int cells[100], i, j, n;
    for (i = 0; i < num_cells; ++i) {
        cells[i] = 0;
    }
    for (i = 0; i < num_cells; ++i) {
        for (j = i; j < num_cells; j += i + 1) {
            if (cells[j] == 0) {
                cells[j] = 1;
            } else {
                cells[j] = 0;
            }
        }
    }
    n = 0;
    for (i = 0; i < num_cells; ++i) {
        n += cells[i];
    }
    return n;
}

int main() {

    int n, num_cells, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &num_cells);
        printf("%d\n", calc(num_cells));
    }

    return 0;
}
