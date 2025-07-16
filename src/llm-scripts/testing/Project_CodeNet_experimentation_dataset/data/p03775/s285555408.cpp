#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    ll ex = 0;
    while (n % i == 0) {
      ++ex;
      n /= i;
    }
    res.push_back({i, ex});
  }
  if (n != 1) res.push_back({n, 1});
  return res;
}

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  ll n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  vector<ll> primes;
  for (auto v : prime_factorize(n)) {
    for (ll i = 0; i < v.second; i++) {
      primes.push_back(v.first);
    }
  }
  vector<ll> ans;
  ll tmp1, tmp2;
  for (int bit = 0; bit < 1 << primes.size(); bit++) {
    tmp1 = tmp2 = 1;
    for (int j = 0; j < primes.size(); j++) {
      if (bit & 1 << j) {
	tmp1 *= primes[j];
      } else {
	tmp2 *= primes[j];
      }
    }
    ans.push_back(max(to_string(tmp1).size(), to_string(tmp2).size()));
  }

  cout << *min_element(ans.begin(), ans.end()) << endl;
  return 0;
}
