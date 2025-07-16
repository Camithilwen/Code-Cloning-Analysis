#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 105;
int n, m;
int dp[maxn][maxn], row[maxn][maxn][maxn], col[maxn][maxn][maxn];
char a[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  return true;
}

void solve() {
  int sx, sy;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'E') {
        sx = i;
        sy = j;
      }
    }
  }
  if (sx < n - sx - 1) {
    for (int i = 0; 2 * i < n; i++) {
      for (int j = 0; j < m; j++) {
        swap(a[i][j], a[n - i - 1][j]);
      }
    }
    sx = n - sx - 1;
  }
  if (sy < m - sy - 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; 2 * j < m; j++) {
        swap(a[i][j], a[i][m - j - 1]);
      }
    }
    sy = m - sy - 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      row[i][j][j] = (a[i][j] == 'o');
      for (int k = j + 1; k < m; k++) {
        row[i][j][k] = row[i][j][k - 1] + (a[i][k] == 'o');
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      col[i][j][j] = (a[j][i] == 'o');
      for (int k = j + 1; k < n; k++) {
        col[i][j][k] = col[i][j][k - 1] + (a[k][i] == 'o');
      }
    }
  }
  int ans = 0;
  for (int x = 0; x + sx < n; x++) {
    for (int y = 0; y + sy < m; y++) {
      dp[sx][sy] = (a[x + sx][y + sy] == 'o');
      for (int i = sy - 1; i >= 0; i--) {
        dp[sx][i] = dp[sx][i + 1] + (a[x + sx][y + i] == 'o');
      }
      for (int i = sx - 1; i >= 0; i--) {
        dp[i][sy] = dp[i + 1][sy] + (a[x + i][y + sy] == 'o');
        for (int j = sy - 1; j >= 0; j--) {
          dp[i][j] = max(dp[i][j + 1] + col[y + j][x + i][min(x + sx, x + i + n - sx - 1)],
                         dp[i + 1][j] + row[x + i][y + j][min(y + sy, y + j + m - sy - 1)]);
        }
      }
      ans = max(ans, dp[0][0]);
    }
  }
  printf("%d\n", ans);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
