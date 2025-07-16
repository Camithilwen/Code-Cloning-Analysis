#include <iostream>

using namespace std;

const int MAX = 10e5;

int main() {
  int N; cin >> N;
  int dp[MAX];
  for (int i = 0; i < MAX; i++) {
    dp[i] = -1;
  }
  for (int i = 0; i < N; i++) {
    int A; cin >> A;
    auto it = lower_bound(dp + MAX - N, dp + MAX, A);
    *--it = A;
  }
  
  int ans = 0;
  for (int i = 1; i <= MAX; i++) {
    if (dp[MAX - i] == -1) {
      ans = i - 1;
      break;
    }
  }
  cout << ans << endl;
}