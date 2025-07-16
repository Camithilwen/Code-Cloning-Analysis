#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
//#define int long long
using namespace std;
typedef long long ll;

#define INF 99999999

int n, k;
int dis[100][100];
int t, a, b, c, d, e;

signed main()
{
	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0) break;

		rep(i,n) rep(j,n) if (i == j) {
			dis[i][j] = 0;
		} else {
			dis[i][j] = INF;
		}

		rep(i,k) {
			cin >> t;
			if (t == 0) {
				cin >> a >> b;
				a--; b--;
				
				if (dis[a][b] == INF) {
					cout << -1 << endl;
				} else {
					cout << dis[a][b] << endl;
				}
			} else if (t == 1) {
				cin >> c >> d >> e;
				c--; d--;

				dis[c][d] = min(dis[c][d], e);
				dis[d][c] = min(dis[d][c], e);

				rep(i,n) rep(j,n) {
					dis[i][j] = min(dis[i][j], min(dis[i][c] + dis[c][d] + dis[d][j], dis[i][d] + dis[d][c] + dis[c][j]));
					dis[j][i] = min(dis[j][i], min(dis[j][c] + dis[c][d] + dis[d][i], dis[j][d] + dis[d][c] + dis[c][i]));
				}
			}
		}
	}
}