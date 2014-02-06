#include <stdio.h>

int measure(char s[51], int n) {
    int i, j, r = 0;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (s[i] > s[j]) {
                ++r;
            }
        }
    }
    return r;
}

int sort_by_measure(int index[100][2], int m) {
    int i, j, k;
    for (i = 0; i < m; ++i) {
        for (j = i + 1; j < m; ++j) {
            if (index[i][1] > index[j][1]) {
                k = index[i][0];
                index[i][0] = index[j][0];
                index[j][0] = k;
                k = index[i][1];
                index[i][1] = index[j][1];
                index[j][1] = k;
            }
        }
    }
}

int main() {

    int n, m, index[100][2], i;
    char strings[100][51];
    
    scanf("%d%d", &n, &m);

    for (i = 0; i < m; ++i) {
        scanf("%s", strings[i]);
        index[i][0] = i;
        index[i][1] = measure(strings[i], n);
    }

    sort_by_measure(index, m);

    for (i = 0; i < m; ++i) {
        printf("%s\n", strings[index[i][0]]);
    }

    return 0;
}
