#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k;
  string s;
  cin >> k >> s;
  cout << ((s.size() <= k) ? s : (s.substr(0, k) + "...")) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}