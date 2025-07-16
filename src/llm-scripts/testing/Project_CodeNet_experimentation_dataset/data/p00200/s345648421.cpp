#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000000
int main(){
	int n, m, a, b, cost, ti, k, p, q, r, point = 0;
	int cost_[101][101], time_[101][101];
	while ( cin >> n >> m && (n != 0 && m != 0)){
		for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) { cost_[i][j] = time_[i][j] = MAX; }
		for (int i = 0; i < n; i++){
			cin >> a >> b >> cost >> ti;
			cost_[a-1][b-1] = cost;
			cost_[b-1][a-1] = cost;
			time_[a-1][b-1] = ti;
			time_[b-1][a-1] = ti;
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < m; j++){
				for (int o = 0; o < m; o++){
						cost_[j][o] = min(cost_[j][o], cost_[j][i] + cost_[i][o]);
						time_[j][o] = min(time_[j][o], time_[j][i] + time_[i][o]);
				}
			}
		}cin >> k;
		for (int i = 0; i < k; i++){
			cin >> p >> q >> r;
			if (r != 1) cout << cost_[p-1][q-1] << endl;
			else cout << time_[p-1][q-1] << endl;
		}
	}
	return 0;
}