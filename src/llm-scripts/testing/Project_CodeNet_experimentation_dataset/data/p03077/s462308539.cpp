#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<ll> a(5);
  ll minimum=1e18;
  rep(i,5){
    cin >> a[i];
    minimum = min(minimum,a[i]);
  }
  
  if(n <= minimum){
    cout << 5 << endl;
  }else{
    ll times = ceil((n-minimum)*1.0/minimum);
    cout << times + 5 << endl;
  }

  return(0);
}