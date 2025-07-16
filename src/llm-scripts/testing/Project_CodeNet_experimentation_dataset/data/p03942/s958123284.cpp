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

const int maxn = 1e6 + 100;
int n;
char s[maxn], t[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", s);
  scanf("%s", t);
  return true;
}

vector<int> pos[300];

void solve() {
  {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        ok = false;
      }
    }
    if (ok) {
      printf("0\n");
      return;
    }
  }
  for (int i = 0; i < 300; i++) {
    pos[i].clear();
  }
  for (int i = 0; i < n; i++) {
    pos[s[i]].pb(i);
  }
  vector<int> xs;
  vector<int> want;
  for (int i = n - 1; i >= 0; i--) {
    if (i == 0 || t[i] != t[i - 1]) {
      int mx = sz(xs) ? xs.back() : inf;
      mx = min(mx, i);
      int j = (int) (upper_bound(pos[t[i]].begin(), pos[t[i]].end(), mx) - pos[t[i]].begin());
      j--;
      if (j == -1) {
        printf("-1\n");
        return;
      }
      xs.pb(pos[t[i]][j]);
      want.pb(i);
    }
  }
  reverse(xs.begin(), xs.end());
  reverse(want.begin(), want.end());
  vector<int> magic;
  for (int i = 0; i < sz(xs); i++) {
    magic.pb(xs[i] - i);
  }
  magic.pb(want.back() - sz(xs) + 1);
  int ans = 1;
  for (int i = 0; i < sz(xs); i++) {
    int j = (int) (lower_bound(magic.begin(), magic.end(), want[i] - i) - magic.begin());
    ans = max(ans, 1 + j - i);
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