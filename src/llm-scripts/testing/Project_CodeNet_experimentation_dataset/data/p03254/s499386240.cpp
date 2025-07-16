#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a));
  int ans = 0;
  rep(i, n){
    if(i != n - 1){
      if(x > 0 && x - a.at(i) >= 0){
        ans++;
        x -= a.at(i);
      }else break;
    }else{
      if(x == a.at(i)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}