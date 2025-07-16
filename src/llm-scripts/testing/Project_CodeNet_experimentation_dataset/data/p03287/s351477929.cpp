#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

ll choose(ll n){
  return n * (n - 1) / 2;
}
int main(){
  ll N, M; cin >> N >> M;
  vector<ll> a(N); rep(i, N) cin >> a[i];

  vector<ll> s(N + 1, 0);
  rep(i, N) s[i + 1] = s[i] + a[i];
  map<ll, ll> mp;
  for (int i = 1; i < N + 1; ++i) mp[s[i] % M]++;
  ll ans = 0;
  for (auto v: mp){
    ans += choose(v.second);
  }
  ans += mp[0];
  cout << ans << endl;
}
