#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define li long long
#define itn int

using namespace std;

inline int nxt(){
	int n;
	scanf("%d", &n);
	return n;
}

const int N = 111 * 111 / 3;
int dp[N][N];

int main(){

	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int posX = 0, posY = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j] == 'E'){
				posX = i;
				posY = j;
			}
		}
	}

	vector<int> i1, i2, j1, j2;
	for (int i = 0; i <= posX; i++){
		for (int j = posX; j < n; j++){
			i1.push_back(i);
			i2.push_back(j);
		}
	}
	for (int i = 0; i <= posY; i++){
		for (int j = posY; j < m; j++){
			j1.push_back(i);
			j2.push_back(j);
		}
	}

	vector<vector<int>> prefX(n, vector<int>(m + 1, 0)), prefY(n + 1, vector<int>(m, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			prefX[i][j + 1] = prefX[i][j] + (a[i][j] == 'o' ? 1 : 0);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			prefY[i + 1][j] = prefY[i][j] + (a[i][j] == 'o' ? 1 : 0);
		}
	}

	int q = i1.size(), w = j1.size();
	vector<vector<int>> pos1(posX + 1, vector<int>(n - posX));
	for (int i = 0; i < q; i++)
		pos1[i1[i]][i2[i] - posX] = i;
	vector<vector<int>> pos2(posY + 1, vector<int>(m - posY));
	for (int i = 0; i < w; i++)
		pos2[j1[i]][j2[i] - posY] = i;

	dp[pos1[posX][0]][pos2[posY][0]] = 0;
	for (int i = posX; i >= 0; i--){
		for (int ii = 0; ii < n - posX; ii++){
			for (int j = posY; j >= 0; j--){
				for (int jj = 0; jj < m - posY; jj++){
					int l = j, r = jj + posY, u = i, d = ii + posX;
					int actl = jj, actr = m - 1 - (posY - j), actu = ii, actd = n - 1 - (posX - i);
					// if (l == posY && r == posY && u == posX && d == posX)
					// 	continue;
					int& res = dp[pos1[i][ii]][pos2[j][jj]];
					if (r > posY)
						res = max(res, dp[pos1[i][ii]][pos2[j][jj - 1]] + (r > actr ? 0 : prefY[min(d, actd) + 1][r] - prefY[max(u, actu)][r]));
					if (l < posY)
						res = max(res, dp[pos1[i][ii]][pos2[j + 1][jj]] + (l < actl ? 0 : prefY[min(d, actd) + 1][l] - prefY[max(u, actu)][l]));
					if (d > posX)
						res = max(res, dp[pos1[i][ii - 1]][pos2[j][jj]] + (d > actd ? 0 : prefX[d][min(r, actr) + 1] - prefX[d][max(l, actl)]));
					if (u < posX)
						res = max(res, dp[pos1[i + 1][ii]][pos2[j][jj]] + (u < actu ? 0 : prefX[u][min(r, actr) + 1] - prefX[u][max(l, actl)]));
				}
			}
		}
	}

	int ans = 0;
	for (int i = posX; i >= 0; i--){
		for (int ii = 0; ii < n - posX; ii++){
			for (int j = posY; j >= 0; j--){
				for (int jj = 0; jj < m - posY; jj++){
					// cerr << i << " " << ii + posX << " " << j << " " << jj + posY << " " << dp[pos1[i][ii]][pos2[j][jj]] << "\n";
					ans = max(ans, dp[pos1[i][ii]][pos2[j][jj]]);
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
