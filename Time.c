#include <stdio.h>
int main() {
    int T, A;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &A);
    if (A % 6)
        printf("N\n");
     else printf("Y\n");
    }
    return 0;
}