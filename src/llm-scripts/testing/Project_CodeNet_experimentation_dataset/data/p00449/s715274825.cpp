#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int main() {
  int n,k;
  while(cin >> n >> k, n && k) {

    long long INF = 1e10;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for(int i = 0;i < n;i++) dist[i][i] = 0;

    for(int q = 0;q < k;q++) {
      int Q;
      cin >> Q;
      if(Q == 0) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(dist[a][b] < INF) {
          cout << dist[a][b] << endl;
        }
        else {
          cout << -1 << endl;
        }
      }
      else {
        long long c,d,e;
        cin >> c >> d >> e;
        c--;
        d--;
        dist[c][d] = min(dist[c][d], e);
        dist[d][c] = min(dist[d][c], e);

        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) {
          dist[i][j] = min(dist[i][j], dist[i][c] + dist[c][d] + dist[d][j]);
        }

        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) {
          dist[i][j] = min(dist[i][j], dist[i][d] + dist[d][c] + dist[c][j]);
        }
      }
    }
  }
}

