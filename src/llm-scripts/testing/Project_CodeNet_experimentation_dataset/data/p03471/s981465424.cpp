#include <bits/stdc++.h>
//#pragma GCC diagnostic error "-Wconversion"
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(vec) vec.begin(), vec.end()
#define mp(a, b) make_pair(a, b)
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = (1e9 + 7);
using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
ll dp[100010];
ll gcd(ll x, ll y){
  return y == 0 ? x : gcd(y, x % y);
}
ll lcg(ll x, ll y){
  return x * y / gcd(x, y);
}
ll digits(ll x){
  ll length = 0;
  while (x > 0){
    x /= 10;
    length++;
  }
  return length;
  if (x == 0) return 0;
}
map<ll, ll> factor(ll n){
  map<ll, ll> ans;
  ll a = 2;
  while (n >= a * a){
    if (n % a == 0){
      ans[a]++;
      n /= a;
    }
    else a++;
  }
  ans[n]++;
  return ans;
}
template<class T> inline bool chmin(T& a, T b){
  if (a > b){
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b){
  if (a < b){
    a = b;
    return true;
  }
  return false;
}

int main(){
  cout << fixed << setprecision(15);
  int ans = 0;
  //string ans = "No";

  int n, y; cin >> n >> y;

  rep(i, n + 1){
    rep(j, n - i + 1){
      if (i * 10000 + j * 5000 + (n - i - j) * 1000 == y){
        cout << i << " " << j << " " << (n - i - j) << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;

  //cout << ans << endl;
  return 0;
}