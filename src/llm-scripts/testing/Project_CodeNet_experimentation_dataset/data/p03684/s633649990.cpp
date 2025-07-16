#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int p[N];
pair<pair<int, int>, int> c[N];
pair< int, pair<int, int> > e[N];

int group(int a) {
  if (p[a] == -1) {
    return a;
  }
  return p[a] = group(p[a]);
}

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    c[i] = make_pair(make_pair(x, y), i);
  }
  for (int it = 0; it < 2; it++) {
    sort(c, c + n);
    for (int i = 0; i < n - 1; i++) {
      int x = c[i].second;
      int y = c[i + 1].second;
      int d = abs(c[i + 1].first.first - c[i].first.first);
      e[it * (n - 1) + i] = make_pair(d, make_pair(x, y));
    }
    for (int i = 0; i < n; i++) {
      swap(c[i].first.first, c[i].first.second);
    }
  }
  sort(e, e + 2 * n - 2);
  fill_n(p, n, -1);
  long long ans = 0;
  for (int i = 0; i < 2 * n - 2; i++) {
    int x = group(e[i].second.first);
    int y = group(e[i].second.second);
    int d = e[i].first;
    if (x == y) {
      continue;
    }
    p[x] = y;
    ans += d;
  }
  printf("%lld\n", ans);
  return 0;
}