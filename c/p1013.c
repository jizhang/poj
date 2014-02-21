#include <stdio.h>

int main() {

    int n, i, j;
    char data[9][13];
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < 9; ++j) {
            scanf("%s", data[j]);
        }
    }

    for (j = 0; j < 9; ++j) {
        printf("%s", data[j]);
    }

    return 0;
}
