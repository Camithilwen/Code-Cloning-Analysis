#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

template<class T>
void print(vector<T> a) {
  cout << "[ ";
  REP(i, a.size()) cout << a[i] << " ";
  cout << "]" << endl;
}

void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...);
}

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

ll n, x;
vector<ll> s;
vector<vector<ll>> table;
ll MOD = 1000000000 + 7;
ll powmod(ll v, ll x) {
  if (x == 0) return 1;
  if (x % 2 == 0) {
    ll tmp = powmod(v, x / 2);
    return (tmp * tmp) % MOD;
  } else {
    return (powmod(v, x - 1) * v) % MOD;
  }
}

#define DP table[i][a]
ll dfs(ll i, ll a) {
  if (DP != -1) return DP;
  if (i == n) return DP = a;

  // double p = 1. / (n - i);
  ll p = powmod(n - i, MOD - 2);
  return DP = ((dfs(i + 1, a % s[i]) * p) % MOD + (dfs(i + 1, a) * ((1 - p + MOD) % MOD)) % MOD) % MOD;

  /* if (i == n - 1) return DP = a % s[n - 1]; */
  /* return DP = (dfs(i + 1, a % s[i]) + dfs(i + 1, a)) % MOD; */
}

int main() {
  cin >> n >> x;
  s = vector<ll>(n);
  REP(i, n) cin >> s[i];
  sort(s.begin(), s.end(), greater<ll>());
  table = vector<vector<ll>>(n + 1, vector<ll>(x + 1, -1));
  ll fact = 1;
  FOR(i, 1, n) {
    (fact *= i) %= MOD;
  }
  cout << dfs(0, x) * fact % MOD << endl;
}
