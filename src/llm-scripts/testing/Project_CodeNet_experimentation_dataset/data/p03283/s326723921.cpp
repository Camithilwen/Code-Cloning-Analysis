#include <iostream>

using namespace std;

int table[501][501];
int C[501][501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;

  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    table[l][r]++;
  }
  for (int i = 1; i <= N; i++) {
    C[i][1] = table[i][1];
    for (int j = 2; j <= N; j++) {
      C[i][j] = C[i][j - 1] + table[i][j];
    }
  }
  for (int i = 0; i < Q; i++) {
    int p, q;
    cin >> p >> q;

    int ans = 0;
    for (int i = p; i <= q; i++) {
      ans += C[i][q] - C[i][p - 1];
    }
    cout << ans << endl;
  }

  return 0;
}
