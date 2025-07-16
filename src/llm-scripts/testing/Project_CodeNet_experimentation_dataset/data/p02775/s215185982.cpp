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

const int INF = 1001001001;

int main(){
  string s;
  cin >> s;
  reverse(ALL(s));
  s.push_back('0');
  vector<vector<int>> dp(s.size()+1, vector<int>(2, INF));
  dp.at(0).at(0) = 0;
  rep(i, s.size())rep(j, 2){
    int now = s.at(i) - '0';
    now += j;
    rep(a, 10){
      int ni = i+1, nj = 0;
      int b = a - now;
      if(b < 0){
        nj++;
        b += 10;
      }
      dp.at(ni).at(nj) = min(dp.at(ni).at(nj), dp.at(i).at(j)+a+b);
    }
  }
  cout << dp.at(s.size()).at(0) << endl;
  return 0;
}