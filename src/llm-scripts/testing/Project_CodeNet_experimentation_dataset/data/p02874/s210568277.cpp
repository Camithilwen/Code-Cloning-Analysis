#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define debugArray(x, n)                                      \
  cerr << __LINE__ << ": " << #x << " = {";                   \
  for (long long hoge = 0; (hoge) < (long long)(n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];                   \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  long long L[N], R[N];
  for (int i = 0; i < N; i++) cin >> L[i] >> R[i];
  int idx[N];
  iota(idx, idx + N, 0);
  // debugArray(idx, N);
  auto step = [&]() {
    long long leftl[N + 1], leftr[N + 1], rightl[N + 1], rightr[N + 1];
    leftl[0] = 0, leftr[0] = INT_MAX;
    for (int i = 0; i < N; i++) {
      int j = idx[i];
      leftl[i + 1] = max(leftl[i], L[j]);
      leftr[i + 1] = min(leftr[i], R[j]);
    }
    rightl[N] = 0, rightr[N] = INT_MAX;
    for (int i = N - 1; i >= 0; i--) {
      int j = idx[i];
      rightl[i] = max(rightl[i + 1], L[j]);
      rightr[i] = min(rightr[i + 1], R[j]);
    }
    // debugArray(leftl, N + 1);
    // debugArray(leftr, N + 1);
    // debugArray(rightl, N + 1);
    // debugArray(rightr, N + 1);
    long long ret = 0;
    for (int i = 0; i < N - 1; i++) {
      ret = max(ret, max(0ll, leftr[i + 1] - leftl[i + 1] + 1)
                         + max(0ll, rightr[i + 1] - rightl[i + 1] + 1));
    }
    for (int i = 0; i < N; i++) {
      int j = idx[i];
      int ll = max(leftl[i], rightl[i + 1]);
      int rr = min(leftr[i], rightr[i + 1]);
      ret = max(ret, max(0, rr - ll + 1) + R[j] - L[j] + 1);
    }
    return ret;
  };
  long long ans = 0;
  sort(idx, idx + N,
       [&](int l, int r) { return L[l] == L[r] ? R[l] > R[r] : L[l] < L[r]; });
  ans = max(ans, step());
  sort(idx, idx + N,
       [&](int l, int r) { return R[l] == R[r] ? L[l] > L[r] : R[l] < R[r]; });
  ans = max(ans, step());
  cout << ans << '\n';
  return 0;
}
