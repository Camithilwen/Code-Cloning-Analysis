#include "assert.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <vector>

using namespace std;

#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, n, a) for (int i = n; i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int, int> PII;
mt19937 mrand(random_device{}());

inline int in() {
  char ch = getchar();
  int f = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return f * x;
}

const int inf = (1 << 30);
const int mod = 998244353;
const int N = 100010;

LL cnt[50][30];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
#endif
  int n = in();
  int tmp = 1e9, A = 0, B = 0;
  while (tmp % 2 == 0)
    ++A, tmp /= 2;
  while (tmp % 5 == 0)
    ++B, tmp /= 5;
  cerr << A << " " << B << endl;
  LL ans = 0;
  rep(_, 1, n) {
    double x;
    cin >> x;
    LL tmp = llround(x * 1e9) ;
    int a = 0, b = 0;
    while (tmp % 2 == 0)
      ++a, tmp /= 2;
    while (tmp % 5 == 0)
      ++b, tmp /= 5;
    rep(i, 0, 49) rep(j, 0, 29) {
      if (i + a >= A * 2 && j + b >= B * 2)
        ans += cnt[i][j];
    }
    cnt[a][b]++;
    cerr << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
