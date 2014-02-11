#include <stdio.h>
#include <string.h>

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

int number[100000][7], count[100000];

void process(char s[100]) {
    int i, j, n[7], found, equals;

    j = 0;
    for (i = 0; i < strlen(s); ++i) {    
        if (s[i] >= '0' && s[i] <= '9') {
            n[j++] = s[i] - '0';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            n[j++] = mapping[s[i] - 'A'];
        }
    }
    
    found = 0;
    for (i = 0; i < 100000; ++i) {
    
        if (count[i] == 0) {
            break;
        }
        
        equals = 1;
        for (j = 0; j < 7; ++j) {
            if (number[i][j] != n[j]) {
                equals = 0;
                break;
            }
        }
        if (equals) {
            count[i] += 1;
            found = 1;
            break;
        }
    }
    if (!found) {
        for (j = 0; j < 7; ++j) {
            number[i][j] = n[j];
        }
        count[i] = 1;
    }
}

void output() {
    int i, j, k, t, greater, has;
    
    for (i = 0; i < 100000; ++i) {
    
        if (count[i] == 0) {
            break;
        }
        
        for (j = i + 1; j < 100000; ++j) {
        
            if (count[j] == 0) {
                break;
            }
            
            if (count[j] == 1) {
                continue;
            }
                        
            greater = 1;
            for (k = 0; k < 7; ++k) {
                if (number[i][k] < number[j][k]) {
                    greater = 0;
                    break;
                } else if (number[i][k] > number[j][k]) {
                    break;
                }
            }
            
            if (greater) {
                for (k = 0; k < 7; ++k) {
                    t = number[i][k];
                    number[i][k] = number[j][k];
                    number[j][k] = t;
                }
                t = count[i];
                count[i] = count[j];
                count[j] = t;
            }
        }
    
    }
    
    has = 0;
    for (i = 0; i < 100000; ++i) {
    
        if (count[i] <= 1) {
            break;
        }
                
        for (k = 0; k < 7; ++k) {
            if (k == 3) {
                printf("-");
            }
            printf("%d", number[i][k]);
        }
        printf(" %d\n", count[i]);
        has = 1;
    }
    
    if (!has) {
        printf("No duplicates.\n");
    }
    
}

int main() {

    int n, i;
    char s[100];
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%s", s);
        process(s);
    }
    output();

    return 0;
}
