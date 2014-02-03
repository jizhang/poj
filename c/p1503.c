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

static void add(char s[200], char n[200]) {
    int i, p, t;

    p = 0;
    for (i = 0; i < 200; ++i) {
        if (s[i] == '\0' && n[i] == '\0') {
            if (p == 1) {
                s[i] = '0' + 1;
                s[i + 1] = '\0';
            }
            break;
        } else if (s[i] == '\0' && n[i] != '\0') {
            t = n[i] - '0';
            if (p == 1) {
                t += 1;
                p = 0;
            }
            if (t > 9) {
                s[i] = '0' + (t - 10);
                p = 1;
            } else {
                s[i] = '0' + t;
            }
            s[i + 1] = '\0';
        } else if (s[i] != '\0' && n[i] == '\0') {
            t = s[i] - '0';
            if (p == 1) {
                t += 1;
                p = 0;
            }
            if (t > 9) {
                s[i] = '0' + (t - 10);
                p = 1;
            } else {
                s[i] = '0' + t;
            }
        } else {
            t = (s[i] - '0') + (n[i] - '0');
            if (p == 1) {
                t += 1;
                p = 0;
            }
            if (t > 9) {
                s[i] = '0' + (t - 10);
                p = 1;
            } else {
                s[i] = '0' + t;
            }
        }
    }
}

int main() {
    char n[200], s[200];
    s[0] = '\0';
    while (1) {
        scanf("%s", n);
        if (strcmp(n, "0") == 0) {
            break;
        }

        revert(n);
        add(s, n);
    }
    revert(s);
    printf("%s\n", s);
    return 0;
}
