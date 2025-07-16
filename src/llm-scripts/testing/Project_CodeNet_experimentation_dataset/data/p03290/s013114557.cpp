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

const int N = 12;
const int S = 1e5+5501;

int dp[N][S];
int p[N], c[N];

int rek(int pos, int tot) {
  if (tot <= 0) return 0;
  if (pos < 0) return 1e4;
  int &ret = dp[pos][tot];
  if (ret != -1) return ret;
  ret = rek(pos-1, tot);
  for (int i = 1; i < p[pos]; ++i) {
    ret = min(ret, i+rek(pos-1, tot-i*(pos+1)));
  }
  return ret = min(ret, p[pos]+rek(pos-1, tot-p[pos]*(pos+1)-c[pos]));
}

void solve() {
  memset(dp, -1, sizeof(dp));
  int d, g; scanf("%d%d", &d, &g);
  g /= 100;
  for (int i = 0; i < d; ++i) {
    scanf("%d%d", p+i, c+i);
    c[i] /= 100;
  }
  printf("%d", rek(d-1, g));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
