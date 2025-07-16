#include<bits/stdc++.h>

using namespace std;

const int N = 15;

void cmax(int& x, int y) {
  if (x < y) {
    x = y;
  }
}

int n, m, dist[N][N], value[1 << N], dp[1 << N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int sum = 0;
  for (int i = 0, a, b, c; i < m; ++i) {
    cin >> a >> b >> c;
    --a;
    --b;
    dist[a][b] = dist[b][a] = c;
    sum += c;
  }
  int all = 1 << n;
  for (int i = 1; i < all; ++i) {
    int p = 0;
    while (!(i >> p & 1)) {
      ++p;
    }
    value[i] = value[i ^ (1 << p)];
    for (int j = 0; j < n; ++j) {
      if (j != p && (i >> j & 1)) {
        value[i] += dist[p][j];
      }
    }
  }
  memset(dp, 0xc0, sizeof dp);
  for (int i = 1; i < all; ++i) {
    if ((i & 1) && !(i >> n - 1 & 1)) {
      dp[i][0] = value[i];
    }
  }
  for (int i = 1; i < all; ++i) {
    for (int j = 1; j < n; ++j) {
      if (i >> j & 1) {
        for (int k = (i - 1) & i; k; k = (k - 1) & i) {
          if ((k & 1) && !(k >> j & 1)) {
            for (int l = 0; l < n; ++l) {
              if ((k >> l & 1) && dist[j][l]) {
                cmax(dp[i][j], dp[k][l] + value[i ^ k] + dist[j][l]);
              }
            }
          }
        }
      }
    }
  }
  int answer = 0;
  for (int i = 1; i < all; ++i) {
    cmax(answer, dp[i][n - 1]);
  }
  cout << sum - answer << '\n';
  return 0;
}