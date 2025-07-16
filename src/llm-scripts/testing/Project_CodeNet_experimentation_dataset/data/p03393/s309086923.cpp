#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  string s;
  cin >> s;
  set<char> d;
  for (char c = 'a'; c <= 'z'; c++) d.insert(c);
  for (auto &i : s) d.erase(i);
  if (d.size()) {
    s += *d.begin();
    cout << s << '\n';
    return;
  }
  set<char> g;
  while (s.size()) {
    char c = s.back();
    s.pop_back();
    auto it = g.upper_bound(c);
    if (it != g.end()) {
      s += *it;
      cout << s << '\n';
      return;
    }
    g.insert(c);
  }
  cout << -1 << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
