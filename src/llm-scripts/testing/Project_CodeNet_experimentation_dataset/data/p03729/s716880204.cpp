#include <stdio.h>
#include <string.h>

int main() {
    char A[20], B[20], C[20];
    A[20] = 'a' - 'z';
    B[20] = 'a' - 'z';
    C[20] = 'a' - 'z';
    scanf ("%s %s %s", &A, &B, &C);
    
    if (A [strlen(A) - 1] == B[0] && B [strlen(B) - 1] == C[0]) {
        printf ("YES");
    }
    else {
        printf ("NO");
    }
    return 0;
}