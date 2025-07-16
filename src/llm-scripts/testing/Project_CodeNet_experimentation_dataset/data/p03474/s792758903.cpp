#include <stdio.h>
#include <string.h>

int main() {
    int a, b, c = 0;
    char pscode[50];
    scanf("%d %d", &a, &b);
    scanf("%s", &pscode);
    for (int i = 0; i < strlen(pscode); i++) {
        if (pscode[a] != '-') {
            printf("No");
            return 0;
        }
        if (pscode[i] >= '0' && pscode[i] <= '9') {
            c++;
        }
    }
    if (c != (a+b)) {
        printf("No");
        return 0;
    }
    printf("Yes");
}