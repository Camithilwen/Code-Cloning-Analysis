// template version 1.8

// varibable settings {{{
using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define int long long
#define INF 1e18
// #define INF 2147483647
#define MOD 998244353
#define infile "../test/sample-1.in"
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
#define fi first
#define se second

// }}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)(b-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;

// dump macro
#ifdef PCM
  #include "dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;
// }}}

int dp[300][90005];
int dp2[300][90005];

int solve(){
  int n;
  cin>>n;
  vi a(n); rep(i, n) {cin>>a[i];}
  sort(all(a));
  int S = accumulate(all(a), 0LL);

  int r = (S%2==0 ? S/2 : S/2+1);
  dump(S, r);

  dp[0][a[0]]=1;
  dp[0][0]=2;
  rep(i, 1, n){
    rep(j, S+5){
      dp[i][j+a[i]] += dp[i-1][j];
      dp[i][j+a[i]] %= MOD;
      dp[i][j] += 2*dp[i-1][j];
      dp[i][j] %= MOD;
    }
  }
  int x = 0;
  rep(i, r, S+5){
    x+=dp[n-1][i];
    x%=MOD;
  }

  int A = 1;
  rep(i, n){
    A *= 3;
    A %= MOD;
  }

  int res;
  if (S%2!=0){
    res = A - 3*x;
    res %=MOD;
  }
  else{
    dp2[0][a[0]]=1;
    dp2[0][0]=1;
    rep(i, 1, n){
      rep(j, S+5){
        dp2[i][j+a[i]] += dp2[i-1][j];
        dp2[i][j+a[i]] %= MOD;
        dp2[i][j] += dp2[i-1][j];
        dp2[i][j] %= MOD;
      }
    }
    res = A - (3*x-dp2[n-1][S/2]*3);
    res %=MOD;
  }
  cout << (res<0 ? res+MOD : res) << endl;

  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}
