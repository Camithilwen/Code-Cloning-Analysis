#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  int n; ll x, cnt=0; 
  cin >> n >> x;
  ll a[n];
  rep(i,n) cin >> a[i];

  rep(i,n-1) {
    if(a[i+1] > 0) {
      if(a[i]+a[i+1]>x) {
        cnt += (min(a[i+1],a[i]+a[i+1]-x));
        a[i+1] -= min(a[i+1],a[i]+a[i+1]-x);
      } else ;
    }
    if(a[i]>0) {
      if(a[i]+a[i+1]>x) {
        cnt += (min(a[i],a[i]+a[i+1]-x));
        a[i] -= min(a[i],a[i]+a[i+1]-x);
      } else ;
    }
  }
  //rep(i,n) cout << a[i] << endl;
  cout << cnt << endl;
}