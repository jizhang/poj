#include <stdio.h>

int ks[30];

int valid(int k, int m) {
    int i, j, killed;
    
    for (i = 0; i < k; ++i) {
        ks[i] = 1;
        ks[i + k] = 2;
    }
    
    i = m % (2 * k) - 1;
    killed = 0;
    while (1) {
        
        if (ks[i] == 1) {
            return 0;
        } else if (ks[i] == 2) {
            ks[i] = 0;
            if (++killed == k) {
                return 1;
            }
        }
        
        j = m;
        while (1) {
        
            if (++i == 2 * k) {
                i = 0;
            }
        
            if (ks[i] != 0 && --j == 0) {
                break;
            }
        }
        
    }
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
