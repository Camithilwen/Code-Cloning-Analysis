#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  tuple<long long, long long, char> XYU[N];
  tuple<long long, long long, char> YXU[N];
  tuple<long long, long long, char> XYU_45[N];
  tuple<long long, long long, char> YXU_45[N];
  for (int i = 0; i < N; i++) {
    int x, y;
    char u;
    cin >> x >> y >> u;
    XYU[i] = make_tuple(x, y, u);
    YXU[i] = make_tuple(y, x, u);
    XYU_45[i] = make_tuple(x - y, x + y, u);
    YXU_45[i] = make_tuple(x + y, x - y, u);
  }
  long long ans = INT_MAX;
  sort(XYU, XYU + N);
  sort(YXU, YXU + N);
  sort(XYU_45, XYU_45 + N);
  sort(YXU_45, YXU_45 + N);
  for (int i = 0; i < N; i++) {
    if (get<2>(XYU[i]) != 'U') continue;
    int j = i + 1;
    while (j < N && get<0>(XYU[i]) == get<0>(XYU[j])) {
      if (get<2>(XYU[j]) == 'U') i = j;
      if (get<2>(XYU[j]) == 'D') {
        ans = min(ans, 5 * (get<1>(XYU[j]) - get<1>(XYU[i])));
      }
      j++;
    }
    i = j - 1;
  }

  for (int i = 0; i < N; i++) {
    if (get<2>(YXU[i]) != 'R') continue;
    int j = i + 1;
    while (j < N && get<0>(YXU[i]) == get<0>(YXU[j])) {
      if (get<2>(YXU[j]) == 'R') i = j;
      if (get<2>(YXU[j]) == 'L') {
        ans = min(ans, 5 * (get<1>(YXU[j]) - get<1>(YXU[i])));
      }
      j++;
    }
    i = j - 1;
  }

  for (int i = 0; i < N; i++) {
    if (get<2>(XYU_45[i]) != 'R') continue;
    int j = i + 1;
    while (j < N && get<0>(XYU_45[i]) == get<0>(XYU_45[j])) {
      if (get<2>(XYU_45[j]) == 'R') i = j;
      if (get<2>(XYU_45[j]) == 'D') {
        ans = min(ans, 5 * (get<1>(XYU_45[j]) - get<1>(XYU_45[i])));
      }
      j++;
    }
    i = j - 1;
  }

  for (int i = 0; i < N; i++) {
    if (get<2>(XYU_45[i]) != 'U') continue;
    int j = i + 1;
    while (j < N && get<0>(XYU_45[i]) == get<0>(XYU_45[j])) {
      if (get<2>(XYU_45[j]) == 'U') i = j;
      if (get<2>(XYU_45[j]) == 'L') {
        ans = min(ans, 5 * (get<1>(XYU_45[j]) - get<1>(XYU_45[i])));
      }
      j++;
    }
    i = j - 1;
  }

  for (int i = 0; i < N; i++) {
    if (get<2>(YXU_45[i]) != 'R') continue;
    int j = i + 1;
    while (j < N && get<0>(YXU_45[i]) == get<0>(YXU_45[j])) {
      if (get<2>(YXU_45[j]) == 'R') i = j;
      if (get<2>(YXU_45[j]) == 'U') {
        ans = min(ans, 5 * (get<1>(YXU_45[j]) - get<1>(YXU_45[i])));
      }
      j++;
    }
    i = j - 1;
  }

  for (int i = 0; i < N; i++) {
    if (get<2>(YXU_45[i]) != 'D') continue;
    int j = i + 1;
    while (j < N && get<0>(YXU_45[i]) == get<0>(YXU_45[j])) {
      if (get<2>(YXU_45[j]) == 'D') i = j;
      if (get<2>(YXU_45[j]) == 'L') {
        ans = min(ans, 5 * (get<1>(YXU_45[j]) - get<1>(YXU_45[i])));
      }
      j++;
    }
    i = j - 1;
  }

  if (ans == INT_MAX) {
    cout << "SAFE" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
