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
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  rep(i, n) a.at(i) = l + i;
  sort(ALL(a), [](const auto &l1, const auto &l2){
    return abs(l1) < abs(l2);
  });
  int ans = 0;
  rep2(i, 1, n) ans += a.at(i);
  cout << ans << endl;
  return 0;
}