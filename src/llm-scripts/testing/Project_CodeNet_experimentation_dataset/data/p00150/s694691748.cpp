#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10001;

int main()
{
  bool prime[MAXN];

  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;

  for (int i = 2; i * i < MAXN; i++){
    for (int j = i * i; j < MAXN; j += i){
      prime[j] = false;
    }
  }

  int n;
  while (scanf("%d", &n), n){
    for (int i = n;; i--){
      if (prime[i] && prime[i - 2]){
        printf("%d %d\n", i - 2, i);
        break;
      }
    }
  }

  return (0);
}