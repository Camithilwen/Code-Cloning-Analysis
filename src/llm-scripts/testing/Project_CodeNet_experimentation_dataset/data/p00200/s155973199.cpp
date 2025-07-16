#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
int m;
int g1[100][100]; //cost
int g2[100][100]; //time

void floyd()
{
  for (int k = 0; k < m; k++) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
        g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);
      }
    }
  } 
}

signed main()
{
  int n, k;
  int a, b, c, t;

  while (cin >> n >> m, n || m) {
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        g1[i][j] = INF;
        g2[i][j] = INF;
      }
    }

    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c >> t;
      a--;
      b--;
      g1[a][b] = c;
      g1[b][a] = c;
      g2[a][b] = t;
      g2[b][a] = t;
    }

    floyd();

    cin >> k;
    for (int i = 0; i < k; i++) {
      int p, q, r;
      cin >> p >> q >> r;
      if (r == 0) {
        cout << g1[p - 1][q - 1] << endl;
      } else {
        cout << g2[p - 1][q - 1] << endl;
      }
    }
  }
  return (0);
}