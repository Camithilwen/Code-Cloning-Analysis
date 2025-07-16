#include <stdio.h>

int main() {
    int A, B, pos = 0;
    char S[20];
    scanf("%d %d %s", &A, &B, S);
    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] == '-') {
            pos += i;
        }
    }
    pos == A ? puts("Yes") : puts("No");
    return 0;
}
