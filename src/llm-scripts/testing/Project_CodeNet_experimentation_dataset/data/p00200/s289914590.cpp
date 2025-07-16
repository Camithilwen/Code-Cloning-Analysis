#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<list>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

short cost[110][110];
short time_data[110][110];


int main(){
	short n, m;


	while (cin >> n >> m && (n != 0 && m != 0)) {
		short min_ = 20000; // 答えの最小値
		short min_num = 1; // 答えの町

		short from, to, time_, cost_;
		short k;
		short k_from, k_to, info;

		for (short i = 1; i < 110; i++) {
			for (short j = 1; j < 110; j++) {
				if (i == j) {
					cost[i][j] = 0;
					time_data[i][j] = 0;
				} else {
					cost[i][j] = 20000;
					time_data[i][j] = 20000;
				}
			}
		}
		for (short i = 0; i < n; i++) {
			cin >> from >> to >> cost_ >> time_;
			cost[from][to] = cost_;
			cost[to][from] = cost_;
			time_data[from][to] = time_;
			time_data[to][from] = time_;
		}
		for (short k = 1; k <= m; k++) {
			for (short i = 1; i <= m; i++) {
				for (short j = 1; j <= m; j++) {
					cost[i][j] = min((int)cost[i][j], cost[i][k] + cost[k][j]);

					time_data[i][j] = min((int)time_data[i][j], time_data[i][k] + time_data[k][j]);
				}
			}
		}
		// 答えを求める
		cin >> k;
		for (short i = 0; i < k; i++) {
			cin >> k_from >> k_to >> info;
			if (info == 0) {
				cout << cost[k_from][k_to] << endl;
			} else {
				cout << time_data[k_from][k_to] << endl;
			}
		}
		
  }
	return 0;
}