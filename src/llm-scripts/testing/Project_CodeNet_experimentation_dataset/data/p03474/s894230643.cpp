#include <stdio.h>
 
int main() {
  int A, B, pos = 0;
  char S[20];
  scanf("%d %d %s", &A, &B, S);
  for (int i = 0; S[i] != '\0'; i++) {
    (S[i] == '-') ? pos += i + 1 : pos += 0;
  }
  pos == A + 1 ? puts("Yes") : puts("No");
  return 0;
}
