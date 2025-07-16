#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(m);
  vector<string> s(m);
  rep(i, m) cin >> p[i] >> s[i];
  rep(i, m) --p[i];

  vector<int> ac(n, 0), wa(n, 0);
  rep(i, m) {
    if (s[i] == "AC") ++ac[p[i]];
    else if (ac[p[i]] == 0) ++wa[p[i]];
  }

  int co = 0, pe = 0;
  rep(i, n) if (ac[i] > 0) {
    ++co;
    pe += wa[i];
  }
  printf("%d %d\n", co, pe);
  return 0;
}