#include <stdio.h>
#include <string.h>

void add(char result[100], char tmp[100]) {
    int i, p, t, e1 = 0, e2 = 0;
    p = 0;
    for (i = 0; i < 100; ++i) {
        t = 0;
        if (e1 == 1 || result[i] == '\0') {
            e1 = 1;
        } else {
            t += result[i] - '0';
        }
        if (e2 == 1 || tmp[i] == '\0') {
            e2 = 1;
        } else {
            t += tmp[i] - '0';
        }
        t += p;
        p = 0;
        if (t > 9) {
            result[i] = '0' + (t % 10);
            p = 1;
        } else {
            result[i] = '0' + t;
        }
    }
    for (i = 99; i > -1; --i) {
        if (result[i] != '0') {
            result[i + 1] = '\0';
            break;
        }
    }
}

void multiply(char result[100], char initial[7]) {
    char ori[100], tmp[100];
    int i, j, p, t;

    strcpy(ori, result);
    strcpy(result, "0");

    for (i = 0; i < strlen(initial); ++i) {

        for (j = 0; j < i; ++j) {
            tmp[j] = '0';
        }

        p = 0;
        for (j = 0; j < strlen(ori); ++j) {
            t = (ori[j] - '0') * (initial[i] - '0') + p;
            tmp[j + i] = '0' + (t % 10);
            p = t / 10;
        }

        if (p > 0) {
            tmp[j + i] = '0' + p;
            ++j;
        }
        tmp[j + i] = '\0'; 
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

void calc(char result[100], char s[7], int n) {
    char initial[7];
    int i, j = 0, f = 0, len;

    if (n == 0) {
        strcpy(result, "1");
        return;
    }

    for (i = 0; i < 6; ++i) {
        if (s[i] == '.') {
            f = (5 - i) * n;
        } else {
            result[j] = s[i];
            initial[j] = s[i];
            ++j;
        }
    }
    result[j] = '\0';
    initial[j] = '\0';

    revert(result);
    revert(initial);

    for (i = 0; i < n - 1; ++i) {
        multiply(result, initial);
    }

    len = strlen(result);
    for (i = len - 1; i > -1; --i) {
        if (result[i] != '0') {
            result[i + 1] = '\0';
            break;
        }
    }
    if (i == -1) {
        strcpy(result, "0");
        return;
    }

    len = strlen(result);
    if (f >= len) {
        for (i = len; i < f; ++i) {
            result[i] = '0';
        }
        result[i] = '.';
        result[i + 1] = '\0';
    } else {
        for (i = len; i > f - 1; --i) {
            result[i + 1] = result[i];
        }
        result[f] = '.';
    }

    for (i = 0; i < f; ++i) {
        if (result[i] != '0') {
            break;
        }
    }
    if (i == f) {
        ++i;
    }
    for (j = 0; j < 99; ++j) {
        result[j] = result[j + i];
    }

    revert(result);
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
