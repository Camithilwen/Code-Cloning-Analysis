#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<functional>
#include<numeric>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<bitset>
#include<random>

#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define rep(i,n) FOR(i,0LL,n)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define rrep(i,n) RFOR(i,0LL,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define COUNT(a,y,x) upper_bound(all(a), y) - lower_bound(all(a), x)
#define UNIQUE(a) sort(all(a)); a.erase(unique(all(a)), a.end())
#define pb push_back
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> MAP;
const ll inf = 2222222222222222222LL;
const ll mod = 1000000007LL;

ll n = 0, m = 0, ans = 0, tmp = 0, ma = -inf, mi = inf;
string s;
bool ok;
ll dx[9] = { 0,1,-1,0,0,1,1,-1,-1 }, dy[9] = { 0,0,0,1,-1,1,-1,1,-1 };
#define endl '\n'
#pragma endregion
#define MAX 222222


ll dp[MAX];


vll fac, inv, invfac;
void comb_set(ll x = MAX) {
  fac.resize(x + 1, 0);
  invfac.resize(x + 1, 0);
  inv.resize(x + 1, 0);
  fac[0] = inv[1] = invfac[0] = 1;
  FOR(i, 1, x + 1) (fac[i] = fac[i - 1] * i) %= mod;
  FOR(i, 2, x + 1) (inv[i] = (mod - mod / i) * inv[mod%i]) %= mod;
  FOR(i, 1, x + 1) (invfac[i] = invfac[i - 1] * inv[i]) %= mod;
}
ll comb(ll x, ll y) {
  if (x < y) return 0;
  return fac[x] * invfac[x - y] % mod * invfac[y] % mod;
}


int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);



  cin >> n >> m;
  vll v(n);
  rep(i, n) cin >> v[i];
  sort(rall(v));
  comb_set(MAX);
  dp[m] = fac[n];
  rep(i, n) {
    FOR(j, v[i], m + 1) {
      (dp[j%v[i]] += inv[n - i] * dp[j]) %= mod;
      (dp[j] = (((n - i - 1) * inv[n - i]) % mod) * dp[j]) %= mod;
    }
  }
  rep(i, m + 1) (ans += i * dp[i]) %= mod;
  cout << ans << endl;


  return 0;
}