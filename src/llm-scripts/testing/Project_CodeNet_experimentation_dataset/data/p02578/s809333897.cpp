#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ans = 0;
  for (int i = 1; i < N; i++) {
    int d = A[i - 1] - A[i];
    if (d > 0) {
      ans += d;
      A[i] = A[i - 1];
    }
  }

  cout << ans << endl;
  return 0;
}