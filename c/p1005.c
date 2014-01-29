#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static int calc(float x, float y) {
    float dist = sqrt(x * x + y * y);
    int r = 0, n = 0;
    while (dist > r) {
        ++n;
        r = sqrt(50 * n * 2 / M_PI);
    }
    return n;
}

int main() {
    int n, i;
    float x, y;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%f %f", &x, &y);
        printf("Property %d: This property will begin eroding in year %d.\n", i + 1, calc(x, y));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
