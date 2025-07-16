#include <stdio.h>
int isprime(int n) {
  int i;
  for(i = 2; i * i <= n; i++) {
    if(n % i == 0) return 0;
  }
  return 1;
}

int main(){
  int i, n, max;
  while(1){
    scanf("%d", &n);
    if(n == 0) break;
    for(i = n;i > 0;i--){
      if(isprime(i) == 1 && isprime(i - 2) == 1){
        max = i;
        break;
      }
    }
    printf("%d %d\n", max - 2, max);
  }
  return 0;
}