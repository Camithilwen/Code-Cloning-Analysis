#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N;
  cin >> N;
  int c[N], flg=0;
  for (int i = 0; i < N; i++){
    c[i] = 0;
  }
  
  for (int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if (i==0 && tmp==0){
      flg = 1;
    }
    
    c[tmp] += 1;
  }

  if (c[0]==1 && flg == 1) {
    unsigned long long ans = 1, tmp = 1;
    unsigned long long t = 998244353;
    for (int i = 2; i < N; i++){
      if (c[i-1] == 0 && c[i] > 0){
        ans = 0;
        break;
      }else if(c[i] == 0){
        continue;
      }
      
      tmp = c[i-1];
      for (int j = 2; j <= c[i]; j++){
        tmp = tmp % t;
        tmp = tmp * (c[i-1] % t);

      }
      ans = ans % t;
      tmp = tmp % t;
      ans *= tmp;
      ans %= t;
    }
    printf("%llu\n", ans);
  }else{
    printf("0\n");
  }
}
