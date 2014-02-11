#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXN 1000005
#define MAXS 205

typedef struct Node_ {
    int number;
    int count;
    struct Node_ *left;
    struct Node_ *right;
} Node;

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

int parse_number(char s[MAXS]) {

    int i, j = 6, n = 0;
    
    for (i = 0; i < strlen(s); ++i) {    
        if (s[i] >= '0' && s[i] <= '9') {
            n += (s[i] - '0') * power(10, j--);
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            n += mapping[s[i] - 'A'] * power(10, j--);
        }
    }
    
    return n;
}

void increment_number(Node **root, int n) {

    Node *node = *root, **p = root, **pn;

    while (node != NULL) {
        if (node->number == n) {
            break;
        } else if (node->number > n) {
            p = &node;
            pn = &(node->left);
            node = node->left;
        } else {
            p = &node;
            pn = &(node->right);
            node = node->right;
        }
    }
    
    if (node != NULL) {
        node->count += 1;
    } else {
        node = (Node *) malloc(sizeof(Node));
        node->number = n;
        node->count = 1;
        node->left = NULL;
        node->right = NULL;
        
        if (*p == NULL) {
            *p = node;
        } else {
            *pn = node;
        }
        
    }
    
}

void print_numbers(Node *node, int *n) {
    if (node != NULL) {
        print_numbers(node->left, n);
        if (node->count > 1) {
            printf("%03d-%04d %d\n", node->number / 10000, node->number % 10000, node->count);
            *n += 1;
        }
        print_numbers(node->right, n);
    }
}

int main() {

    int n, i;
    char s[MAXS];
    Node *root;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%s", s);
        increment_number(&root, parse_number(s));
    }
    
    n = 0;
    print_numbers(root, &n);
    if (n == 0) {
        printf("No duplicates.\n");
    }

    return 0;
}
