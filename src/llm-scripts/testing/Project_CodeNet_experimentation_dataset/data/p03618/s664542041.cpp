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
  string s;
  cin >> s;
  map<char, int> mp;
  rep(i, s.size()){
    mp[s.at(i)]++;
  }

  ll ans = 1;
  for(auto p : mp){
    for(auto p2 : mp){
      if(p2.first <= p.first) continue;
      ans += (ll)p.second * p2.second;
    }
  }
  cout << ans << endl;
  return 0;
}