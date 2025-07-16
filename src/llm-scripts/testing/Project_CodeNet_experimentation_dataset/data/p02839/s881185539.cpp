#include <stdio.h>
typedef long long ll;

ll abs(ll a) {
  return a > 0 ? a : -a;
}

int main(void) {
  ll i, j, k, h, w;
  scanf("%lld%lld", &h, &w);
  ll a[h][w], b[h][w], d[h][w];
  bool dp[w][80 * (h + w)], tmp[w][80 * (h + w)];
  for(j = 0; j < w; ++j) for(k = 0; k < 80 * (h + w); ++k) dp[j][k] = false;
  for(i = 0; i < h; ++i) for(j = 0; j < w; ++j) scanf("%lld", &a[i][j]);
  for(i = 0; i < h; ++i) for(j = 0; j < w; ++j) scanf("%lld", &b[i][j]), d[i][j] = abs(a[i][j] - b[i][j]);
  for(i = 0; i < w; ++i) for(j = 0; j < 80 * (h + w); ++j) dp[i][j] = false;
  dp[0][d[0][0]] = true;
  for(i = 1; i < w; ++i) for(j = 0; j < 80 * (h + w); ++j) if(dp[i - 1][j]) {
    dp[i][j + d[0][i]] = true;
    dp[i][abs(j - d[0][i])] = true;
  }
  for(k = 1; k < h; ++k) {
    for(i = 0; i < w; ++i) for(j = 0; j < 80 * (h + w); ++j) tmp[i][j] = false;
    for(i = 0; i < 80 * (h + w); ++i) if(dp[0][i]) {
      tmp[0][i + d[k][0]] = true;
      tmp[0][abs(i - d[k][0])] = true;
    }
    for(i = 1; i < w; ++i) for(j = 0; j < 80 * (h + w); ++j) {
      if(tmp[i - 1][j]) {
        tmp[i][j + d[k][i]] = true;
        tmp[i][abs(j - d[k][i])] = true;
      }
      if(dp[i][j]) {
        tmp[i][j + d[k][i]] = true;
        tmp[i][abs(j - d[k][i])] = true;
      }
    }
    for(i = 0; i < w; ++i) for(j = 0; j < 80 * (h + w); ++j) dp[i][j] = tmp[i][j];
  }
  for(i = 0; ; ++i) if(dp[w - 1][i]) {
    printf("%lld", i);
    return 0;
  }
}