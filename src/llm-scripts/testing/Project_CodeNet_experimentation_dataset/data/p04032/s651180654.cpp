#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
template<typename T> inline void add(T& a, T b) { a += b; if (a >= MOD) a -= MOD; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;
  vector<int> BI(26, -10);
  int n = s.size();
  rep(i, n) {
    if(i - BI[s[i] - 'a'] <= 2) {
      cout << BI[s[i] - 'a'] + 1 << " " << i + 1 << endl;
      return 0;
    }
    BI[s[i] - 'a'] = i;
  }
  cout << "-1 -1" << endl;
  return 0;
}
