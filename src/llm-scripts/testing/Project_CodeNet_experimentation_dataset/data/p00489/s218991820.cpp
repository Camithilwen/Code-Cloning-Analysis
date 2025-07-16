#include <iostream>

using namespace std;

int main (void) {
  int G[101][101] = {0}, sum[101] = {0}, rank[101] = {0};
  int a, b, c, d;
  int n;

  cin >> n;

  for(int i = 1; i <= n*(n-1)/2; i++) {
    cin >> a >> b >> c >> d;
    if(c < d) {
      G[a][b] = 0; G[b][a] = 3;
    } else if(c == d) {
      G[a][b] = 1; G[b][a] = 1;
    } else {
      G[a][b] = 3; G[b][a] = 0;
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if (i == j) continue;
      sum[i] += G[i][j];
    }
  }

  //cout << sum[0] << " " << sum[1] << " " << sum[2] << " " << sum[3] << endl;

  int daburi = 1;

  // rankの出し方は俺が考えたアルゴリズムじゃない
  for(int i = 1; i <= n; i++) {
    rank[i] = 1;
    for(int j = 1; j <= n; j++) {
      if(sum[i] < sum[j]) rank[i]++;
    }
  }

  for(int i = 1; i <= n; i++) {
    cout << rank[i] << endl;
  }

  return 0;
}