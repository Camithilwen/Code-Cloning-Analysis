#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
struct edge {
  ll to, cost;
};

int main() {
  int N, M, X, Y; cin >> N >> M >> X >> Y;
  vector<int> x(N); REP(i, N) cin >> x[i];
  vector<int> y(M); REP(i, M) cin >> y[i];
  sort(all(x)); sort(all(y));
  string ans = "War";
  for(int i = X + 1; i <= Y; ++i) {
    if(x[N - 1] < i && i <= y[0]) ans = "No War";
  }
  cout << ans << endl;
}