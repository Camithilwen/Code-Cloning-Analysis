#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    vector<ll> va(n*m+1,0), vb(n*m+1,0);
    rep(i,n) {
      cin >> a[i];
      va[a[i]]++;
    }
    rep(i,m) {
      cin >> b[i];
      vb[b[i]]++;
    }
    vector<ll> num(n*m+1,0);
    rep(i,n) {
      rep(j,m) num[min(a[i],b[j])]++;
    }
    ll ans = 1, s = 0;
    for(int i = n*m; i >= 1; i--) {
      if(va[i] >= 2 || vb[i] >= 2) {
        ans = 0;
      } else if (va[i] == 1 && vb[i] == 1){
        ans *= 1;
      } else if(va[i] == 1 || vb[i] == 1) {
        (ans *= num[i]) %= mod;
      } else {
        (ans *= num[i] + s) %= mod;
      }
      s += num[i] - 1;
    }
    cout << ans << endl;
    return 0;
}