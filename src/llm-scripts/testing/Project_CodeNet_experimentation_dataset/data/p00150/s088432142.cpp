#include<stdio.h>
int isprime(int n){
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0)return 0;
  }
  return 1;
}
int main(){
  int v;
  while(scanf("%d", &v) != EOF) {
    if(v == 0){
      break;
    }
    while(1){
      if(isprime(v) == 1 && isprime(v - 2) == 1){
        printf("%d %d\n", v - 2, v);
        break;
      }else{
        v--;
      }
    }
  }
  return 0;
}