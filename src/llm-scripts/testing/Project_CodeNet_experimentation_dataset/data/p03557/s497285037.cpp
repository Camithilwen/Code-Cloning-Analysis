#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ld = long double; 
int INF = 1e9;

int main(){
  int n;cin >> n;
  vector<int> a(n),b(n),c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  vector<int> bc(n),ab(n);
  int ind = 0;
  rep(i,n){
    while(b[i]>=c[ind]) {
      if(ind == n) break;
      ind++;
    }
    bc[i] = n-ind;
  }
  ind = 0;
  rep(i,n){
    while(a[i] >= b[ind]){
      if(ind == n) break;
      ind++;
    }
    ab[ind]++;
  }
  rep(i,n-1) ab[i+1] += ab[i];
  ll ans = 0;
  rep(i,n) ans += ll(ab[i])*ll(bc[i]);
  cout << ans << endl;

}