#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int h[30];

void solve() {
  string s; cin >> s;
  for (int i = 0; i < (int)s.size(); ++i) {
    ++h[s[i]-'a'];
  }
  long long ans = 1LL*s.size()*(s.size()-1)/2;
  for (int i = 0; i < 30; ++i) {
    if (!h[i]) continue;
    ans -= 1LL*h[i]*(h[i]-1)/2;
  }
  printf("%lld", ans+1);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
