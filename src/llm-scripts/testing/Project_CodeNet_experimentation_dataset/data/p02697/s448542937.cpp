#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  n = 2*m+1;
  vector<pair<int, int>> ans;
  int r;
  if(m % 2 == 0) r = m+1;
  else r = m;
  rep(i, m/2){
    ans.push_back(make_pair(i+1, r-i));
  }
  int l;
  l = r+1;
  rep(i, (m+1)/2){
    ans.push_back(make_pair(l+i, n-i));
  }
  rep(i, m){
    cout << ans.at(i).first << " " << ans.at(i).second << endl;
  }
  return 0;
}