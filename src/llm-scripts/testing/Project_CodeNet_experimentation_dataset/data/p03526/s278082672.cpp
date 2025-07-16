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

Int P[5050];
pair<int, int> A[5050];

int main() {
  int N = in();
  P[0] = 0;
  for (int u = 1; u <= N; ++u) {
    P[u] = INFLL;
  }
  for (int i = 0; i < N; ++i) {
    A[i].first = in();
    A[i].second = in();
  }
  sort(A, A + N, [] (const pair<int, int>& a, const pair<int, int>& b) {
    return a.first + a.second < b.first + b.second;
  });

  for (int i = 0; i < N; ++i) {
    int H = A[i].first;
    int Z = A[i].second;
    for (int u = i; u >= 0; --u) {
      if (P[u] <= H) {
        chmin(P[u + 1], P[u] + Z);
      }
    }
  }

  int res = 0;
  for (int u = 0; u <= N; ++u) {
    if (P[u] < INFLL) {
      chmax(res, u);
    }
  }
  printf("%d\n", res);

  return 0;
}
