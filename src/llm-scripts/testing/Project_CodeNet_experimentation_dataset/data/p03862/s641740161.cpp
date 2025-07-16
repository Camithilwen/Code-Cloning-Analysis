#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  ll ans = 0;
  for(int i=0; i<n-1; ++i){
    int ca = max(0, an[i] +an[i+1] -x);
    ans += ca;
    an[i+1] = max(0, an[i+1] -ca);
  }
  cout << ans << endl;
}