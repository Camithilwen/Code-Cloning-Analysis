#include <stdio.h>
const int MAX_V = 1000000;
int prime[MAX_V];
int main() {
  int i, k, v, n, max = 0;
  for(i = 2; i <= MAX_V; i++) {
    prime[i] = 1;
  }
  for(i = 2; i*i <= MAX_V; i++) {
    if(prime[i]){
      for(k = 2 * i; k <= MAX_V; k += i) {
        prime[k] = 0;
      }
    }
  }
  while(1){
    scanf("%d", &n);
    if(n == 0) break;
    for(i = n;i > 0;i--){
      if(prime[i] == 1 && prime[i - 2] == 1){
        max = i;
        break;
      }
    }
  printf("%d %d\n", max - 2, max);
  }
  return 0;
}