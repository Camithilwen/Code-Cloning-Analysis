#include<iostream>
#include<algorithm>
using namespace std;
static const long long INFTY = (1LL << 32);
int main()
{
	int n, m, p, q, r,i,j,k,a,b,cost,time;
	long long cost_d[101][101], time_d[101][101];
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		for (i = 1; i <= m; i++) {
			for (j = 1; j <= m; j++) {
				cost_d[i][j] = ((i == j) ? 0 : INFTY);
				time_d[i][j] = ((i == j) ? 0 : INFTY);
			}
		}
		for (i = 0; i < n; i++) {
			cin >> a >> b >> cost >> time;
			cost_d[a][b] = cost;
			cost_d[b][a] = cost;
			time_d[a][b] = time;
			time_d[b][a] = time;
		}
		for (k = 1; k <= m; k++) {
			for (i = 1; i <= m; i++) {
				if (cost_d[i][k] == INFTY)continue;
				for (j = 1; j <= m; j++) {
					if (cost_d[k][j] == INFTY)continue;
					cost_d[i][j] = min(cost_d[i][j], cost_d[i][k] + cost_d[k][j]);
					time_d[i][j] = min(time_d[i][j], time_d[i][k] + time_d[k][j]);
				}
			}
		}
		cin >> k;
		for (i = 0; i < k; i++) {
			cin >> p >> q >> r;
			if (r == 0) {
				cout << cost_d[p][q]<<endl;
			}
			else {
				cout << time_d[p][q] << endl;
			}
		}
	}
	return 0;
}