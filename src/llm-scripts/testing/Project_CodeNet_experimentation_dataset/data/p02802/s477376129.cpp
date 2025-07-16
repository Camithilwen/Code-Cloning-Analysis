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
  ll N, M; cin >> N >> M;
  vector<pair<int, int>> ans(N + 1); // 提出数と0, 1の正解か不正解か
  REP(i, M) {
    int p; string S; cin >> p >> S;
    if(S == "WA" && ans[p].second == 0) ans[p].first++;
    else if(S == "AC") ans[p].second = 1;
  }
  ll res = 0; ll pena = 0;
  REP(i, N + 1) {
    if(ans[i].second == 1) {
      res++;
      pena += ans[i].first;
    }
  }
  cout << res << " " << pena << endl;
}