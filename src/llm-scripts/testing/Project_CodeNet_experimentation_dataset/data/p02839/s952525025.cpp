//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
//const int MOD = 998244353;
template<class T> inline int add(T& a, T b, T M = MOD){a=(a+M)%M;b=(b+M)%M;a=(a+b)%M;return a;};
template<class T> inline int mul(T& a, T b, T M = MOD){if(a>=M)a%=M;if(b>=M)b%=M;a*=b;if(a>=M)a%=M;return a;};
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

////////////////////////////////////////////////////////////////////
///////////////////////___modpow___////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret);
  if(n%2)((ret *= a));
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}

vector<ll> fac, finv, inv;
void COMinit(const int MAX = 5000000, const ll &MOD = MOD){
  fac.resize(MAX);finv.resize(MAX);inv.resize(MAX);
  fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
  repd(i,2,MAX){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
ll COM(int n, int k){
  if(n < k)return 0;
  if(n < 0 || k < 0)return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}


////////////////////////////////////////////////////////////////////

int h,w,a[100][100],b[100][100],c[100][100];
bool dp[85][85][20000];
signed main(){
  cin>>h>>w;
  rep(i,h)rep(j,w)cin>>a[i][j];
  rep(i,h)rep(j,w)cin>>b[i][j];
  rep(i,h)rep(j,w)c[i][j] = abs(a[i][j] - b[i][j]);
  dp[0][0][abs(c[0][0])] = true; 
  rep(i,h){
    rep(j,w){
      rep(d,15000){
        if(!dp[i][j][d])continue;
        dp[i][j+1][d+c[i][j+1]] = j+1 < w;
        dp[i][j+1][abs(d-c[i][j+1])] = j+1 < w;
        dp[i+1][j][d+c[i+1][j]] = i+1 < h;
        dp[i+1][j][abs(d-c[i+1][j])] = i+1 < h;
      }
    }
  }
  rep(i,15000){
    if(dp[h-1][w-1][i]){
      cout << i << endl;return 0;
    }
  }
}
