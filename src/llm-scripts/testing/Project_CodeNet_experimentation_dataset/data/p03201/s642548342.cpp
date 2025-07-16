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

const int N = 2e5+23;

int a[N];
map<int, int> m;

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    ++m[a[i]];
  }
  sort(a, a+n, greater<int>());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!m[a[i]]) continue;
    for (int j = 1<<30; j >= a[i]; j >>= 1) {
      int t = 1;
      if (j-a[i] == a[i]) {
	t = 2;
      }
      if (m.count(j-a[i]) && m[j-a[i]] >= t) {
	++ans;
	--m[a[i]];
	--m[j-a[i]];
	break;
      }
    }
  }
  printf("%d", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
