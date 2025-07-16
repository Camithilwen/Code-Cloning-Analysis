#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

const int mod = (int) 1e9 + 7;

void add(int &x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (long long) x * y % mod;
}

int myPower(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

void precalc() {
}


const int maxn = (int) 1e5 + 10;
int table[maxn][3];
int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", table[j] + i);
    }
  }
  return 1;
}

int a[maxn];
int xr[maxn];

int used[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    if (abs(table[i][1] - table[i][0]) != 1 || abs(table[i][2] - table[i][1]) != 1) {
      printf("No\n");
      return;
    }
    a[i] = (table[i][0] - 1) / 3;
    xr[i] = (table[i][0] > table[i][2]);
  }

  for (int i = 0; i < n; ++i) {
    used[i] = 0;
  }
  int whole[2] = {(((n + 1) / 2) & 1), ((n / 2) & 1)};
  for (int i = 0; i < n; ++i) {
    if ((a[i] & 1) != (i & 1)) {
      printf("No\n");
      return;
    }
    whole[!(i & 1)] ^= xr[i];

    if (!used[i]) {
      whole[i & 1] ^= 1;
      for (int x = i; !used[x]; x = a[x]) {
        used[x] = 1;
      }
    }
  }
  if (whole[0] || whole[1]) {
    printf("No\n");
  } else {
    printf("Yes\n");
    //printf("No\n");
  }
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
