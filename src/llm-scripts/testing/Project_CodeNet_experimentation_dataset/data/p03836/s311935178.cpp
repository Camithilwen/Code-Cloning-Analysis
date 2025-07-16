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

int main() {
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  int x = tx - sx; int y = ty - sy;
  vector<string> ans;
  REP(i, y) ans.push_back("U");
  REP(i, x) ans.push_back("R");
  REP(i, y) ans.push_back("D");
  REP(i, x) ans.push_back("L");
  ans.push_back("L");
  REP(i, y + 1) ans.push_back("U");
  REP(i, x + 1) ans.push_back("R");
  ans.push_back("D");
  ans.push_back("R");
  REP(i, y + 1) ans.push_back("D");
  REP(i, x + 1) ans.push_back("L");
  ans.push_back("U");
  REP(i, ans.size()) cout << ans[i];
  cout << endl;
}