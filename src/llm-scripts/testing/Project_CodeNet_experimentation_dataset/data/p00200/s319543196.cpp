#include<iostream>
#include<queue>
#include<vector>
#include<limits>

using namespace std;

struct RequestObj {
	int begin, end, type;
};

int n, m;//???,???????????°
int k;//????????¨????????°
int time_table[100][100];
int cheap_table[100][100];
RequestObj request[200];


const int INF = 10000000;

int main() {
	while (cin >> n >> m, n * m) {

		for (int i = 0; i < m; i++)for (int j = 0; j < m; j++)time_table[i][j] = INF, cheap_table[i][j] = INF;
		
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			cin >> cheap_table[a - 1][b - 1] >> time_table[a - 1][b - 1];
			cheap_table[b - 1][a - 1] = cheap_table[a - 1][b - 1];
			time_table[b - 1][a - 1] = time_table[a - 1][b - 1];
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> request[i].begin >> request[i].end >> request[i].type;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					if (cheap_table[j][i] + cheap_table[i][k] < cheap_table[j][k]) {
						cheap_table[j][k] = cheap_table[j][i] + cheap_table[i][k];
					}
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < m; k++) {
					if (time_table[j][i] + time_table[i][k] < time_table[j][k]) {
						time_table[j][k] = time_table[j][i] + time_table[i][k];
					}
				}
			}
		}
		for (int i = 0; i < k; i++) {
			if (request[i].type == 0) {
				cout << cheap_table[request[i].begin - 1][request[i].end - 1] << endl;
			}
			else {
				cout << time_table[request[i].begin - 1][request[i].end - 1] << endl;
			}
		}

		for (int i = 0; i < m; i++)for (int j = 0; j < m; j++)time_table[i][j] = INF, cheap_table[i][j] = INF;

	}
	return 0;
}