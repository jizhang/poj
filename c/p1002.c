#include <stdio.h>
#include <string.h>

#define MAXN 1000005
#define MAXS 205

int mapping[26] = {
    2, 2, 2, // A, B, C
    3, 3, 3, // D, E, F
    4, 4, 4, // G, H, I
    5, 5, 5, // J, K, L
    6, 6, 6, // M, N, O
    7, -1, 7, 7, // P, Q, R, S
    8, 8, 8, // T, U, V
    9, 9, 9, -1 // W, X, Y, Z
};

int number[MAXN], count[MAXN];

int power(int a, int b) {
    int i, r = a;
    if (b == 0) {
        return 1;
    }
    for (i = 0; i < b - 1; ++i) {
        r *= a;
    }
    return r;
}

void process(char s[MAXS]) {
    int i, j, n, found;

    n = 0;
    j = 6;
    for (i = 0; i < strlen(s); ++i) {    
        if (s[i] >= '0' && s[i] <= '9') {
            n += (s[i] - '0') * power(10, j--);
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            n += mapping[s[i] - 'A'] * power(10, j--);
        }
    }
    
    found = 0;
    for (i = 0; i < MAXN; ++i) {
    
        if (count[i] == 0) {
            break;
        }
        
        if (number[i] == n) {
            count[i] += 1;
            found = 1;
            break;
        }
    }
    if (!found) {
        number[i] = n;
        count[i] = 1;
    }
}

void output() {
    int i, j, k, t, has;
    
    has = 0;
    for (i = 0; i < MAXN; ++i) {
    
        if (count[i] == 0) {
            break;
        }
        
        for (j = i + 1; j < MAXN; ++j) {
        
            if (count[j] == 0) {
                break;
            }
            
            if (count[j] == 1) {
                continue;
            }
            
            if (number[i] > number[j]) {
                t = number[i];
                number[i] = number[j];
                number[j] = t;
                
                t = count[i];
                count[i] = count[j];
                count[j] = t;
            }
        }
        
        if (count[i] > 1) {
            printf("%03d-%04d %d\n", number[i] / 10000, number[i] % 10000, count[i]);
            has = 1;
        }
    }
    
    if (!has) {
        printf("No duplicates.\n");
    }
    
}

int main() {

    int n, i;
    char s[MAXS];
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%s", s);
        process(s);
    }
    output();

    return 0;
}
