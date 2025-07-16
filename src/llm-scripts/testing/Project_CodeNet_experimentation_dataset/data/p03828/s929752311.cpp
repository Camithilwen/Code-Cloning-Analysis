#include <bits/stdc++.h>
using namespace std;

vector<long long> kosu(1001);

void divisor(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    while(n % i == 0){
      kosu[i]++;
      n /= i;
    }
  }
  if(n != 1){
    kosu[n]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  for(int i = 1; i <= N; i++){
    divisor(i);
  }
  long long ans = 1;
  for(int i = 0; i < 1001; i++){
    ans *= kosu[i] + 1;
    ans %= 1000000007;
    }
    cout << ans <<endl;
}