#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  ll t;
  cin >> n >> t;
  vector<ll> a(n);
  ll ans = 0;
  ll lim = a[0] + t;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++){
    if(i == 0) {
      ans = t;
      continue;
    }
    if(lim > a[i]){
      ll ext = (a[i]+t-lim);
      if(ext < 0) continue;
      lim = a[i]+t;
      ans +=  ext;
    }else{
      lim = a[i] + t;
      ans += t;
    }
  }
  cout << ans << endl;
}