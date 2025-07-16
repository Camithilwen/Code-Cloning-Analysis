#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

int solve() {
  int a, b, c; scanf("%d%d%d", &a, &b, &c);
  int h[10] = {};
  ++h[a]; ++h[b]; ++h[c];
  for (int i = 1; i < 10; ++i) if (h[i] == 2) return !printf("Yes");
  return !printf("No");
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
