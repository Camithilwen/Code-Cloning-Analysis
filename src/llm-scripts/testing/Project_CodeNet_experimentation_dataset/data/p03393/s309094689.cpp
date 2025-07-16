#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <deque>     // deque
#include <iomanip>   //setprecsion
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <set>       // set
#include <stack>     // stack
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <utility>   // pair, make_pair
#include <vector>    // vector

#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>  //sin, cos, tan

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define mt(p, q, r) make_tuple(p, q, r)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;
typedef vector<tuple<ll, ll, ll>> vtlll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

template <typename T>
void fin(T a)
{
  cout << a << endl;
  exit(0);
}

//桁数
ll GetDigit(ll num)
{
  return log10(num) + 1;
}

//約数全列挙
vector<ll> enum_div(ll n)
{
  vector<ll> ret;
  for (ll i = 1; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
      {
        ret.push_back(n / i);
      }
    }
  }
  sort(begin(ret), end(ret));
  return ret;
}

//累乗(xのn乗%mod)
ll modpow(ll x, ll n, ll mod = MAX)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

//階乗
ll factorial(ll n)
{
  if (n > 0)
    return n * factorial(n - 1);
  else
    return 1;
}

ll modinv(ll a, ll mod)
{
  ll b = mod, u = 1, v = 0;
  while (b)
  {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= mod;
  if (u < 0)
    u += mod;
  return u;
}

ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
  return a * b / gcd(a, b);
}

void Main()
{
  str s;
  cin >> s;
  set<char> flag;
  rep(i, s.size())
  {
    flag.insert(s[i]);
  }
  for (char i = 'a'; i <= 'z'; i++)
  {
    if (!flag.count(i))
      fin(s + i);
  }
  if (s == "zyxwvutsrqponmlkjihgfedcba")
    fin(-1);
  vc SS;
  SS.pb(s[s.size() - 1]);
  s.pop_back();
  while(1)
  {
    sort(all(SS));
    for(ll i = 0;i < SS.size();i++)
    {
      if(s[s.size() - 1] < SS[i])
      {
        s.pop_back();
        cout << s << SS[i] << endl;
        return;
      }
    }
    SS.pb(s[s.size() - 1]);
    s.pop_back();
  }
}

//前処理
int main()
{
  //ios::sync_with_stdio(false);
  //cin.tie(0);
  cout << fixed << setprecision(20); //高精度少数表示
  //cout << setfill('0') << internal << setw(4); 0埋め４桁
  Main();
  return 0;
}
