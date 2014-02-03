#include <stdio.h>
#include <string.h>

static void revert(char *s) {
    char t;
    int len, i, j;
    
    len = strlen(s);
    for (i = 0, j = len - 1; i < len / 2; ++i, --j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

}

static void add(int s[200], char n[200]) {
    int i, flag;
    flag = 1;
    for (i = 0; i < 200; ++i) {
        if (flag == 1) {
            if (n[i] != '\0') {
                s[i] += n[i] - '0';
            } else {
                flag = 0;
            }
        }
        if (s[i] >= 10) {
            s[i] -= 10;
            s[i + 1] += 1;
        }
    }
}

int main() {
    int s[200], i, flag;
    char n[200];

    for (i = 0; i < 200; ++i) {
        s[i] = 0;
    }

    while (1) {
        scanf("%s", n);
        if (strcmp(n, "0") == 0) {
            break;
        }

        revert(n);
        add(s, n);
    }

    flag = 1;
    for (i = 199; i >= 0; --i) {
        if (flag == 1 && s[i] == 0) {
            continue;
        }
        flag = 0;
        printf("%d", s[i]);
    }

    printf("\n", s);
    return 0;
}
