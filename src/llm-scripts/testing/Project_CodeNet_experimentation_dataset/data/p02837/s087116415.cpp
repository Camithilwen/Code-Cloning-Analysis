#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int A[N];
  vector<pair<int, bool>> xy[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    xy[i].resize(A[i]);
    for (int j = 0; j < A[i]; j++) {
      cin >> xy[i][j].first >> xy[i][j].second;
      xy[i][j].first--;
    }
  }
  int ans = 0;
  for (int s = 1; s < (1 << N); s++) {
    bool isok = true;
    for (int i = 0; i < N; i++)
      if ((s >> i) & 1) {
        for (int j = 0; j < A[i]; j++) {
          isok &= !(((s >> xy[i][j].first) & 1) ^ xy[i][j].second);
        }
      }
    if (isok) ans = max(ans, __builtin_popcount(s));
  }
  cout << ans << '\n';
  return 0;
}
