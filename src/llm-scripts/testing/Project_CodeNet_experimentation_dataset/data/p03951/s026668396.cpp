#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
  int n;
  string s,t;
  cin >> n >> s >>t;
  int sz = s.length();
  int tz = t.length();
  if(sz+tz<=n) {
      cout << n << endl;
      return 0;
  }
  int ma = 0;
  rrep(i,tz) {
      int ss = sz-1;
      int tmp=0;
      while(i>=0 && ss>=0) {
         // cout << s[ss]<<t[i]<<ss<<" "<<i<<" " << endl;
          if(s[ss]==t[i]) {
              if(i==0) {
                  cout << sz+tz-(sz-ss) << endl;
                return 0;
              }
              ss--;
              tmp++;
          }else {
              if(tmp>0) i++;
              break;
          }
          i--;
      }
      ma=max(tmp,ma);
      //cout << ma << endl;
  }
  cout << sz+tz-ma << endl;
  return 0;
}

