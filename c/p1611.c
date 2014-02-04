#include <stdio.h>

#define MAXN 30001
int rank[MAXN], p[MAXN], num[MAXN];

void make_set(int x) {
    p[x] = x;
    rank[x] = 0;
    num[x] = 1;
}

void union_set(int x, int y) {
    
    x = find_set(x);
    y = find_set(y);

    if (x == y) {
        return;
    }

    if (rank[x] > rank[y]) {
        p[y] = x;
        num[x] += num[y];
    } else {
        p[x] = y;
        if (rank[x] == rank[y]) {
            rank[y] += 1;
        }
        num[y] += num[x];
    }
}

int find_set(int x) {
    if (x != p[x]) {
        p[x] = find_set(p[x]);
    }
    return p[x];
}

int main() {
    int n, m, i, j, g, x, y;

    while (1) {
        
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }

        if (m == 0) {
            printf("1\n");
            continue;
        }

        for (i = 0; i < n; ++i) {
            make_set(i);
        }

        for (i = 0; i < m; ++i) {
            scanf("%d%d", &g, &x);
            for (j = 1; j < g; ++j) {
                scanf("%d", &y);
                union_set(x, y);
                x = y;
            }
        }

        printf("%d\n", num[find_set(0)]);
    }

    return 0;
}
