#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int main(){
  ll n, m, d;
  cin >> n >> m >> d;
  long double x = 0;
  if(2 * d >= n){
    x += n - d;
    x += n - d;
    x /= n * n;
  }
  else if(d == 0){
    x += n;
    x /= n * n;
  }
  else{
    x += d;
    x += 2 * (n - 2 * d);
    x += d;
    x /= n * n;
  }
  cout << fixed << setprecision(10);
  cout << x * (m - 1) << endl;
}