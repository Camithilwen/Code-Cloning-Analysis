#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<long long> v(n);
  
  for (int i = 0; i < n; i++)
    cin >> v.at(i);
  
  long long mod = 1000000007;
  long long sum = 0;
  
  for (int i = 0; i < n; i++) {
    sum += v.at(i);
    sum %= mod;
  }
  
  long long ans;
  
  ans = sum * sum % mod;
  
  for (int i = 0; i < n; i++) {
    ans -= (long long)v.at(i) * v.at(i) % mod;
  }
  
  while (ans < 0) ans += mod;
    
  ans *= (mod + 1) / 2;
  
  cout << ans % mod << endl;
}
  