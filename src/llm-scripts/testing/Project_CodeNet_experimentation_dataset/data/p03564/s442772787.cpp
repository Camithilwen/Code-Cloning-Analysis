#include <stdio.h>

int main() {
    int n, k, number = 1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        number = number * 2 < number + k ? number * 2 : number + k;
    }
    printf("%d\n", number);
    return 0;
}
