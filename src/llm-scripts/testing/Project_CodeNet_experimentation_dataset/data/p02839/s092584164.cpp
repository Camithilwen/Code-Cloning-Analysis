#include <cstdio>
#include <cstdlib>
#include <cstring>
#define CLR(x) memset((x), false, sizeof(x))
const int MAXD = 12801;
const int MAXN = 81;
int  A[2][MAXN][MAXN];
bool   dp[MAXN][MAXN][MAXD];
int H, W;

int solve() {
  CLR(dp);
  dp[0][0][0] = true;
  dp[0][1][0] = true;
  dp[1][0][0] = true;
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      for (int k = 0; k < MAXD; ++k) {
        int d = std::abs(A[0][i][j] - A[1][i][j]);
        int nk1 = k + d;
        if (nk1 < MAXD) {
          dp[i][j][k] |= dp[i-1][j][nk1] | dp[i][j-1][nk1];
        }
        int nk2 = std::abs(k - d);
        dp[i][j][k] |= dp[i-1][j][nk2] | dp[i][j-1][nk2];
      }
    }
  }
  for (int k = 0; k < MAXD; ++k) {
    if (dp[H][W][k]) {
      return k;
    }
  }
  return -1;
}

int main() {
  scanf(" %d%d", &H, &W);
  for (int k = 0; k < 2; ++k) {
    for (int i = 1; i <= H; ++i) {
      for (int j = 1; j <= W; ++j) {
        scanf("%d", &A[k][i][j]);
      }
    }
  }
  printf("%d\n", solve());
  return 0;
}