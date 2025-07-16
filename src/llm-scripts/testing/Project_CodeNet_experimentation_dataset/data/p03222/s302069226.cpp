#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 1000000007; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;


signed main() {
  int H, W, K; 
  cin >> H >> W >> K;

  

  vector<vector<int>> dp(H+1, vector<int>(W, 0));
  dp[0][0] = 1;
  
  REP(i, H) REP(j, W) REP(k, (1<<(W-1))){
    bool ok = true;
    REP(l, W-2){
      if(((k >> l)&1) && ((k >> (l+1))&1)) ok = false;
    }
    if(ok){
      if(j >= 1 && ((k >> (j-1))&1)){
        dp[i+1][j-1] += dp[i][j];
        dp[i+1][j-1] %= MOD;
      }else if(j <= W-2 && ((k >> j)&1)){
        dp[i+1][j+1] += dp[i][j];
        dp[i+1][j+1] %= MOD;
      }else{
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= MOD;
      }
    }
  }

  cout << dp[H][K-1] << endl;

  return 0;
}