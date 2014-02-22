#include <stdio.h>
#include <string.h>

void calc(char data[9][13], char result[2][6]) {
    strcpy(result[0], "K");
    strcpy(result[1], "light");
}

int main() {

    int n, i, j;
    char data[9][13], result[2][6];

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < 9; ++j) {
            scanf("%s", data[j]);
        }
        calc(data, result);
        printf("%s is the counterfeit coin and it is %s.\n", result[0], result[1]);
    }

    return 0;
}
