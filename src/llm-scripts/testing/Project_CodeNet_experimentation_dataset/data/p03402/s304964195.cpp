#include <iostream>
#ifdef MBP
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define REP(i, n) for (long long int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP_R(i, n) for (long long int i = (n - 1); i >= 0; --i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((long long int)(x).size())
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

#define INF INT_MAX
#define INFLL LLONG_MAX
#define PB push_back
#define MOD 1000000007LL
#define LSB(x) __builtin_ctzll(x)
#define MSB(x) 64LL - __builtin_clzll(x) - 1LL
#define MSBINT(x) 32LL - __builtin_clz(x)
#define BITCNT(x) __builtin_popcountll(x)

using namespace std;
using uif = uint_fast64_t;
using ll = long long int;
using vec = vector<ll>;
using mat = vector<vector<ll>>;
using pa = pair<ll, ll>;
using tTree = __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template <class T>
using PQ = priority_queue<T>;
template <class T>
using PQG = priority_queue<T, vector<T>, greater<T>>;

const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
const ll dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template <class T>
bool chmax(T &, const T &);
template <class T>
bool chmin(T &, const T &);

ll qp(ll a, ll b);
ll qp(ll a, ll b, ll mo);

ll mod_pow(ll, ll);
ll mod_add(ll, ll);
ll mod_mul(ll, ll);
ll mod_div(ll, ll);
void make_fact(ll);
void make_invfact(ll);
void init_fact();

ll combination(ll, ll);

#define FACSIZE 200002LL

ll invfac[FACSIZE];
ll fac[FACSIZE];

pa pos(ll x)
{
  pa p;
  p.first = (x / 49) * 2 + 1;
  p.second = (x % 49) * 2 + 1;

  return p;
}

int main(void)
{
  ll a, b;
  cin >> a >> b;

  mat field(100, vec(100, 0));
  REP(i, 50)
  REP(j, 100)
  field[i][j] = 1;

  REP(i, a - 1)
  {
    auto p = pos(i);
    field[p.first][p.second] = 0;
  }
  REP(i, b - 1)
  {
    auto p = pos(i);
    field[p.first + 50][p.second] = 1;
  }
  cout << 100 << " " << 100 << endl;
  REP(i, 100)
  {
    REP(j, 100)
    {
      auto x = field[i][j];
      if (x == 1)
      {
        cout << '#';
      }
      else
      {
        cout << '.';
      }
    }
    cout << endl;
  }

  return 0;
}

template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}

ll qp(ll a, ll b)
{
  ll ans = 1LL;
  do
  {
    if (b & 1LL)
      ans = 1LL * mod_mul(ans, a) % MOD;
    a = 1LL * mod_mul(a, a) % MOD;
  } while (b >>= 1LL);
  return ans;
}
ll qp(ll a, ll b, ll mo)
{
  ll ans = 1LL;
  do
  {
    if (b & 1LL)
      ans = 1LL * (ans % mo) * (a % mo);
    a = 1LL * (a % mo) * (a % mo);
  } while (b >>= 1LL);
  return ans;
}

ll mod_pow(ll x, ll r)
{
  if (r == 0)
    return 1;
  else if (r == 1)
    return x % MOD;
  else if (r % 2 == 0)
  {
    ll t = mod_pow(x, r / 2) % MOD;
    return t * t % MOD;
  }
  else
  {
    ll t = mod_pow(x, r / 2) % MOD;
    ll k = t * t % MOD;
    return k * x % MOD;
  }
}
ll mod_add(ll a, ll b)
{
  return (a + b) % MOD;
}

ll mod_mul(ll a, ll b)
{
  return (a * b) % MOD;
}

ll mod_div(ll a, ll b)
{
  return mod_mul(a, mod_pow(b, MOD - 2));
}

void make_fact(ll n)
{
  fac[0] = 1;
  REP(i, n)
  {
    fac[i + 1] = mod_mul(fac[i], i + 1);
  }
}

void make_invfact(ll n)
{
  invfac[n] = mod_pow(fac[n], MOD - 2);
  REP_R(i, n)
  {
    invfac[i] = mod_mul(invfac[i + 1], i + 1);
  }
}

void init_fact()
{
  make_fact(FACSIZE - 1);
  make_invfact(FACSIZE - 1);
}

ll combination(ll n, ll c)
{

  return mod_mul(fac[n], mod_mul(invfac[c], invfac[n - c]));
}
///////////////fact
/*
  init_fact();
  cout << fac[5] << endl;
  cout << invfac[5] << endl;
  cout << combination(8, 4) << endl;
  cout << combination(31, 8) << endl;
  //*/
///////////////////
