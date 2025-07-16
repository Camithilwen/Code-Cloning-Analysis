#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <random>
#include <tuple>
#include <iomanip>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n-1); i >= 0; i--)
#define pb push_back
#define f first
#define s second
const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
ll MOD = 1000000007;
//ll MOD  = 998244353;
vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}

ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}
ll pow_mod(ll x, ll k){
  x %= MOD; x += MOD; x %= MOD;
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}

ll inverse(ll x){return pow_mod(x, MOD - 2);};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y){return x / gcd(x, y) * y;};

ll kai_mod(ll x){
  if(x == 0) return 1;
  return x * kai_mod(x-1) % MOD;
}

/*
//コンビネーション
const int MAXcomb = 200010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAXcomb; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}
*/


//MODなしバージョン
vector<vector<ll>> memo(60, vector<ll>(60, -1));
//コンビネーション
ll comb(int n, int k){
    if(memo[n][k] != -1) return memo[n][k];
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    if(n == 0 || k == 0) return 1;
    return memo[n][k] = comb(n-1, k) + comb(n-1, k-1);
}


ll N, M;
string S, T;
ll solve(string blue, string red){
  //Tを使って、red, blueを作る。
  if(blue.size() < red.size()) swap(red, blue);

  ll rl = red.size();
  ll dp[N+1][rl+1];
  rep(i, N+1){
    rep(j, rl + 1){
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  rep(i, N){
    rep(j, rl + 1){
      if(j != rl && T[i] == red[j]){
        dp[i+1][j+1] += dp[i][j];
      }
      if(T[i] == blue[i-j]){
        dp[i+1][j] += dp[i][j];
      }
    }
  }
  return dp[N][rl];
}

int main(){
  cin >> N >> S;
  T = S;
  reverse(T.begin(), T.end());
  ll ans = 0;
  rep(i, (1 << N)){
    string red = "", blue = "";
    rep(j, N){
      if((i >> j) & 1) red += S[j];
      else blue += S[j];
    }
    ans += solve(red, blue);
  }
  cout << ans << endl;
}
