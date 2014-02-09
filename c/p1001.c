#include <stdio.h>
#include <string.h>

void add(int result[100], int tmp[100]) {
    int i;

    for (i = 0; i < 100 - 1; ++i) {
        result[i] += tmp[i];
        if (result[i] > 9) {
            result[i] -= 10;
            result[i + 1] += 1;
        }
    }
}

void multiply(int result[100], int initial[6]) {
    int ori[100], tmp[100], i, j, p;

    memcpy(ori, result, 100 * sizeof(int));
    memset(result, 0, 100 * sizeof(int));

    for (i = 0; i < 6; ++i) {

        memset(tmp, 0, 100 * sizeof(int));
        p = 0;
        for (j = 0; j < 100 - i; ++j) {
            tmp[j + i] = ori[j] * initial[i] + p;
            p = 0;
            if (tmp[j + i] > 9) {
                p = tmp[j + i] / 10;
                tmp[j + i] %= 10;
            }
        }

        add(result, tmp);
    }

}

void revert(char *s) {
    int i, j, len;
    char t;
    len = strlen(s);
    for (i = 0, j = len - 1; i < len / 2; ++i, --j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void calc(char r[100], char s[7], int n) {
    int result[100], initial[6], i, j, f, flag;

    if (n == 0) {
        strcpy(r, "1");
        return;
    }

    memset(result, 0, 100 * sizeof(int));
    memset(initial, 0, 6 * sizeof(int));

    j = 0;
    f = 0;
    for (i = 5; i > -1; --i) {
        if (s[i] == '.') {
            f = (5 - i) * n;
        } else {
            result[j] = s[i] - '0';
            initial[j] = result[j];
            ++j;
        }
    }

    for (i = 0; i < n - 1; ++i) {
        multiply(result, initial);
    }

    j = 0;
    flag = 0;
    for (i = 0; i < f; ++i) {
        if (flag || result[i] > 0) {
            r[j++] = '0' + result[i];
            flag = 1;
        }
    }
    if (j > 0) {
        r[j++] = '.';
    }
    for (i = f; i < 100; ++i) {
        r[j++] = '0' + result[i];
    }

    for (i = 99; i > -1; --i) {
        if (r[i] != '0') {
            r[i + 1] = '\0';
            break;
        }
    }
    if (i == -1) {
        r[1] = '\0';
    }

    revert(r);
}

int main() {
    char s[7], result[100];
    int n;
    while (scanf("%s%d", s, &n) == 2) {
        calc(result, s, n);
        printf("%s\n", result);
    }
    return 0;
}
