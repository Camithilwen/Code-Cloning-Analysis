#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;

  bool f[10] = {};
  int num[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  for (int i = 0; i < M; i++) {
    int A;
    cin >> A;
    f[A] = true;
  }
  vector<int> dp(N + 1, -1);
  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < 10; j++) {
      if (!f[j] || i - num[j] < 0 || dp[i - num[j]] == -1) continue;
      dp[i] = max(dp[i], dp[i - num[j]] + 1);
    }
  }
  for (int i = N; i > 0;) {
    for (int j = 9; j >= 1; j--) {
      if (f[j] && i - num[j] >= 0 && dp[i] == dp[i - num[j]] + 1) {
        cout << j;
        i -= num[j];
        break;
      }
    }
  }
}