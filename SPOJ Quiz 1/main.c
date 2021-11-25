#include <stdio.h>
int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%.11f\n", (1.0/2.0 * (1.0-1.0/(1.0 + n))-(1.0/2.0*(1.0/2.0 - 1.0/(2.0+n)))+1.0/2.0));
    }
    return 0;
}
