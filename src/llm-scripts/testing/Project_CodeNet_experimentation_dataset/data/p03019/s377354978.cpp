//c++ -std=gnu++14 a.cpp
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <climits>
#include <fstream>
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<ll, ll> P;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define revrep(i, n) for(int i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
#define chmin(x, y) x = min(x, y);
#define chmax(x, y) x = max(x, y);
#define sz(x) ((int)(x).size())

//const ll INFL = LLONG_MAX;//10^18 = 2^60
const ll INFL = 1LL<<60;
//const int INF = INT_MAX;
const int INF = 1 << 30;//10^9
//const int MOD = 1000000007;
const int MOD = 998244353;
//int MOD = 1000000007;
double EPS = 1e-10;

vector<ll> dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};

void pres(double A){printf("%.12lf\n", A);}
void BinarySay(ll x, ll y = 60){rep(i, y) cout << (x>>(y-1-i) & 1); cout << endl;}
ll cnt_bit(ll x){return __builtin_popcountll(x);}

ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x; k /= 2;
  }
  return res;
}

ll pow_mod(ll x, ll k){
  x %= MOD;
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

ll lcm(ll x, ll y){
  ll res = x / gcd(x, y);
  res *= y;
  return res;
};


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

const int MAXkai = 200010;
ll kai_memo[MAXkai];
ll kai(ll N){
  if(kai_memo[N] != 0) return kai_memo[N];
  if(N <= 1) return 1;
  return kai_memo[N] = N * kai(N-1) % MOD;
}

ll disit(ll s, ll base = 10){
  ll res = 0;
  while(s){
    res++;
    s /= base;
  }
  return res;
}

//約数の列挙O(√n)
vector<int> divisor(int n){
    vector<int> res(0);
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


int N, X;
struct test{ll b, l, u, up;};
vector<test> T;
ll need;
ll sum[100010];
bool comp_test(test a, test b){
  return a.up < b.up;
}

bool can(ll tar){
  ll all = tar / X;
  if(all >= N) return 1;
  ll rest = tar % X;
  //all個のテストで満点を取る
  rep(i, N){
    //i番目のテストは中途半端にとる
    ll get;
    if(i < all) get = sum[all+1] - T[i].up;
    else get = sum[all];
    get += max(rest * T[i].l, rest * T[i].u - T[i].b * (T[i].u - T[i].l));
    if(get >= need) return 1;
  }
  return 0;
}

void solve(){
  cin >> N >> X;
  rep(i, N){
    ll b, l, u;
    cin >> b >> l >> u;
    ll up = (X - b) * u + b * l;
    T.pb({b, l, u, up});
    need += b * l;
  }
  sort(T.begin(), T.end(), comp_test);
  reverse(T.begin(), T.end());
  rep(i, N){
    sum[i+1] = sum[i] + T[i].up;
  }
  ll ng = -1, ok = INFL;
  while(ok - ng > 1){
    ll mid = (ok + ng) / 2;
    if(can(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  solve();
}
