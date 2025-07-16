#include <iostream>
using namespace std;

int main(){
  long long n, a, b; cin >> n >> a >> b;
  long long x[n];
  for(int i = 0; i < n; ++i) cin >> x[i];
  long long dp[n+1];
  dp[0] = 0;
  dp[1] = 0;
  for(int i =2; i <= n; ++i){
    dp[i] = min(a*(x[i-1]-x[i-2]), b) + dp[i-1];
  }
  cout << dp[n] << endl;
  return 0; 
}