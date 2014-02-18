#include <stdio.h>

int ks[30];

int valid(int k, int m) {
    int i, j;
    
    for (i = 0; i < k; ++i) {
        ks[i] = 1;
        ks[i + k] = 2;
    }
    
    // TODO

    return 1;
}

int calc(int k) {

    int m = k + 1;
    while (1) {
    
        if (valid(k, m)) {
            return m;
        }
    
        ++m;
    }
}

int main() {

    int k;
    while (scanf("%d", &k) == 1) {
        if (k == 0) {
            break;
        }
        printf("%d\n", calc(k));
    }

    return 0;
}
