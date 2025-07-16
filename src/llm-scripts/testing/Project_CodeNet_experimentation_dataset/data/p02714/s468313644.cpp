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

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  string s;
  cin >> n >> s;
  ll ans;
  map<char, ll> m;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') m['R']++;
    if (s[i] == 'G') m['G']++;
    if (s[i] == 'B') m['B']++;
  }
  ans = m['R'] * m['G'] * m['B'];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int k = j + j - i;
      if (k < n) {
	if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) ans--;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
