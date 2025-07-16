#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,T;
  cin >> N >> T;
  int A[N],B[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  int DP[N][T+1];
  int invDP[N][T+1];
  for (int i = 0; i <= T; i++) {
    if (A[0] <= i) {
      DP[0][i] = B[0];
    } else {
      DP[0][i] = 0;
    }
  }
  for (int i = 0; i <= T; i++) {
    if (A[N-1] <= i) {
      invDP[N-1][i] = B[N-1];
    } else {
      invDP[N-1][i] = 0;
    }
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= T; j++) {
      if (A[i] > j) {
        DP[i][j] = DP[i-1][j];
      } else {
        DP[i][j] = max(DP[i-1][j],DP[i-1][j-A[i]] + B[i]);
      }
    }
  }

  for (int i = N-2; i >= 0; i--) {
    for (int j = 0; j <= T; j++) {
      if (A[i] > j) {
        invDP[i][j] = invDP[i+1][j];
      } else {
        invDP[i][j] = max(invDP[i+1][j],invDP[i+1][j-A[i]] + B[i]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < N-1; i++) {
    int res = 0;
    for (int j = 0; j <= T-1; j++) {
      res = max(res,DP[i-1][j] + invDP[i+1][T-1-j]);
    }
    ans = max(ans,res+B[i]);
  }
  ans = max(ans,B[0] + invDP[1][T-1]);
  ans = max(ans,B[N-1] + DP[N-2][T-1]);
  cout << ans << endl;
  return 0;
}