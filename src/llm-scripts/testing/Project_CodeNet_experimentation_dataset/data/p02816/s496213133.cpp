#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

void solve(const vector<int>& A, const vector<int>& B, vector<int>& mask, int bit) {
  int n = A.size() - 1, m = B.size();
  vector<int> f(m);
  f[0] = 0;
  int k = 0;
  for (int i = 1; i < m; ++i) {
    for (; k > 0 && B[k] != B[i]; k = f[k - 1]);
    if (B[k] == B[i]) k++;
    f[i] = k;
  }
  k = 0;
  for (int i = 0; i < n; ++i) {
    for (; k > 0 && B[k] != A[i]; k = f[k - 1]);
    if (B[k] == A[i]) k++;
    if (k == m) {
      mask[i - m + 1] |= bit;
      k = f[k - 1];
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  vector<int> A(2 * n), B(n), mask(n);
  for (int k = 0; k < 30; ++k) {
    for (int i = 0; i < n; ++i) {
      A[i + n] = A[i] = (a[i] >> k) & 1;
    }
    for (int i = 0; i < n; ++i) B[i] = (b[i] >> k) & 1;
    solve(A, B, mask, 1 << k);
    for (int i = 0; i < n * 2; ++i) A[i] = 1 - A[i];
    solve(A, B, mask, 1 << k);
  }
  for (int i = 0; i < n; ++i) {
    if (mask[i] != (1 << 30) - 1) continue;
    printf("%d %d\n", i, a[i] ^ b[0]);
  }
  return 0;
}
