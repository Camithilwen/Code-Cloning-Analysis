#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  set<char> d;
  for (char c = 'a'; c <= 'z'; c++) d.insert(c);
  for (auto &i : s) d.erase(i);
  if (d.empty()) cout << "None" << '\n';
  else cout << *d.begin() << '\n';
}
