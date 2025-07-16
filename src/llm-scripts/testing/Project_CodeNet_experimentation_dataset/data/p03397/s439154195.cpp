#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

const Int MO = 1000000007;
int N;
char S[300050], T[300050];
Int dp1[300050][2], lef[300050];
Int dp2[300050][2][2];

inline void add(Int& a, Int b) {
  a += b;
  if (a >= MO) a -= MO;
}

Int solve() {
  if (T[0] == '1' && T[N - 1] == '1') {
    Int ret = 1;
    for (int i = 0; i < N; ++i) {
      if (T[i] == '?') {
        (ret *= 2) %= MO;
      }
    }
    return ret;
  }
  if (T[0] == '1') {
    reverse(T, T + N);
  }

  memset(dp1, 0, sizeof(dp1));
  memset(lef, 0, sizeof(lef));
  dp1[0][0] = 1;
  for (int i = 0; i < N; ++i) {
    if (T[i] != '1') {
      add(dp1[i + 1][0], dp1[i][0]);
      add(dp1[i + 1][0], dp1[i][1]);
    }
    if (T[i] != '0') {
      add(dp1[i + 1][1], dp1[i][0]);
      add((i % 2 == 0) ? lef[i + 1] : dp1[i + 1][1], dp1[i][1]);
    }
  }

  reverse(T, T + N);
  memset(dp2, 0, sizeof(dp2));
  dp2[0][0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int flg = 0; flg < 2; ++flg) {
      if (T[i] != '1') {
        add(dp2[i + 1][flg][0], dp2[i][flg][0]);
        add(dp2[i + 1][flg][0], dp2[i][flg][1]);
      }
      if (T[i] != '0') {
        int nflg = flg || (i == 0);
        add(dp2[i + 1][nflg][1], dp2[i][flg][0]);
        nflg |= (i % 2 == 0);
        add(dp2[i + 1][nflg][1], dp2[i][flg][1]);
      }
    }
  }

  Int ret = lef[N];
  for (int i = 1; i < N; i += 2) {
    add(ret, lef[i] * (dp2[N - i][1][0] + dp2[N - i][1][1] + dp2[N - i][0][1]) % MO);
  }

  return ret;
}

int main() {
  scanf("%s", S);
  N = strlen(S);
  if (N == 1) {
    puts(S[0] == '0' ? "0" : "1");
    return 0;
  }

  Int res = 0;
  for (int i = 0; i < 4; ++i) {
    memcpy(T, S, sizeof(T));
    if (S[0] != '?' && S[0] != (i & 1) + '0') continue;
    if (S[N-1] != '?' && S[N-1] != (i / 2) + '0') continue;
    T[0] = (i & 1) + '0';
    T[N-1] = (i / 2) + '0';
    (res += solve()) %= MO;
  }

  printf("%lld\n", res);

  return 0;
}