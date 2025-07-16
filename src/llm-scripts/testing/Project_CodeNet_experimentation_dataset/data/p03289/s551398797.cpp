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
  string S; cin >> S;
  string ans = "AC";
  if(S[0] != 'A') ans = "WA";
  if(S[1] != tolower(S[1])) ans = "WA";
  if(S[S.size() - 1] != tolower(S[S.size() - 1])) ans = "WA";
  int cnt = 0;
  for(int i = 2; i < S.size() - 1; ++i) {
    if(S[i] == 'C') cnt++;
    if(cnt > 1) ans = "WA";
    if(i == S.size() - 2 && cnt == 0) ans = "WA";
  }
  cout << ans << endl;
}