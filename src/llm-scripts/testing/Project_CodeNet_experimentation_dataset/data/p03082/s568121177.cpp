#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int S = 100005;
const int mo = 1e9 + 7;

int n, x;
int a[N + 5];
int f[N + 5][S + 5];

int main() {
#ifdef Wearry
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
#endif

  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a + n, greater<int>()); 

  f[0][x] = 1;
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j <= x; ++j) if (f[i][j]) {
      f[i + 1][j % a[i]] = (f[i + 1][j % a[i]] + f[i][j]) % mo;
      f[i + 1][j] = (f[i + 1][j] + 1ll * f[i][j] * (n - 1 - i)) % mo;
    }

  int ans = 0;
  for (int i = 0; i <= x; ++i) {
    ans = (ans + 1ll * f[n][i] * i) % mo;
  }
  cout << ans << endl;

  return 0;
}
