#define C
typedef long long readtype;

/* Header {{{ */
#ifdef C
#include <stdio.h>
#include <math.h>
#include <string.h>
#define isdigit(a) ((a) >= '0' && (a) <= '9' ? true : false)
template<typename type> type abs(type a) { return a < 0 ? -a : a; }
template<typename type> type min(type a, type b) { return a < b ? a : b; }
template<typename type> type beMin(type &a, type b) { return a = (a < b ? a : b); }
template<typename type> type max(type a, type b) { return a > b ? a : b; }
template<typename type> type beMax(type &a, type b) { return a = (a > b ? a : b); }
template<typename type> void swap(type &a, type &b) { type c; c = a; a = b; b = c; }
#endif

#ifdef Cpp
#include <bits/stdc++.h>
using namespace std;
#endif

typedef long long var;

readtype read() {
  readtype a = 0, c = getchar(), s = 0;
  while (!isdigit(c)) s |= c == '-', c = getchar();
  while (isdigit(c)) a = a * 10 + c - 48, c = getchar();
  return s ? -a : a;
}
/* }}} */

const int N = 311;

int n, m;
int a[N][N], have[N], pos[N];
bool ban[N];

bool check(int t);

int main() {
  /*
#ifndef ONLINE_JUDGE
  freopen("source.in", "r", stdin);
  freopen("source.out", "w", stdout);
#endif
*/
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) a[i][j] = read();
  }
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (!check(mid)) l = mid + 1;
    else r = mid;
  }
  printf("%d\n", l);
  return 0;
}

bool check(int t) {
  memset(ban, false, sizeof(ban));
  memset(have, 0, sizeof(have));
  memset(pos, 0, sizeof(pos));
  for (int i = 1; i <= n; ++i) have[a[i][++pos[i]]]++;
  while (true) {
    bool ok = true;
    for (int i = 1; i <= m; ++i) {
      if (have[i] <= t) continue;
      ok = false;
      ban[i] = true;
    }
    if (ok) break;
    for (int i = 1; i <= n; ++i) {
      while (pos[i] <= m && ban[a[i][pos[i]]]) {
        have[a[i][pos[i]]]--;
        have[a[i][++pos[i]]]++;
      }
      if (pos[i] > m) return false;
    }
  }
  return true;
}
