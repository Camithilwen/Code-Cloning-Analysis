#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (1e+9)+7;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  ll sm = 0;
  for(int i=0; i<n; i++){
    cin >> a[i];
    sm = (sm + a[i]) % MOD;
  }
  ll ans = 0;
  for(int i=0; i<n; i++){
    sm -= a[i];
    if(sm < 0) sm += MOD;
    ans = (ans + (a[i] * (sm)) % MOD) % MOD;
  }
  cout << ans << endl;
}