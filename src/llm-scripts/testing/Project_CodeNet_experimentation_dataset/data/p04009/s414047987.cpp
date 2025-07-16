#include<bits/stdc++.h>
using namespace std;

#define MAX 102

int h;
int w;

char buf[MAX][MAX];

short dp[MAX][MAX][MAX][MAX];
pair<int, int> E;
int im[MAX][MAX];
int gt(int a, int b){
	if (a < 0 || b < 0){
		return 0;
	}
	return im[a][b];
}
int rect(int x1, int x2, int y1, int y2){
	return gt(x2, y2) + gt(x1 - 1, y1 - 1) - gt(x2, y1 - 1) - gt(x1 - 1, y2);
}
int dfs(int a, int b, int c, int d){
	if (a > b || c > d)return 0;
	return dp[a][b][c][d];
}
int main(){
	cin >> h >> w;
	for (int i = 0; i < h; i++){
		scanf("%s", buf[i]);
	}
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			if (buf[i][j] == 'E'){
				E = make_pair(i, j);
			}
			if (buf[i][j] == 'o'){
				im[i][j]++;
			}
		}
	}
	for (int i = 0; i < h; i++){
		for (int j = 1; j < w; j++){
			im[i][j] += im[i][j - 1];
		}
	}
	for (int j = 0; j < w; j++){
		for (int i = 1; i < h; i++){
			im[i][j] += im[i - 1][j];
		}
	}
	int a;
	int b;
	int c;
	int d;
	short int can;
	short int add;
	for (int rng = 1; rng <= h; rng++){
		for (int rng2 = 1; rng2 <= w; rng2++){
			for (int i = 0; i + rng <= h; i++){
				for (int j = 0; j + rng2 <= w; j++){
					a = i;
				 b = a + rng - 1;
					c = j;
					d = j + rng2 - 1;
					{
						can = E.first + a + 1;
						if (a + 1 <= can&&can <= b){
							add = rect(can, can, max(c, E.second - (w - d) + 1), min(d, E.second + c));
							add += dfs(a + 1, b, c, d);
							dp[a][b][c][d] = add;
						}
					}

					//choose b
					{
					 can = E.first - (h - b);
						if (a <= can&&can <= b - 1){
						 add = rect(can, can, max(c, E.second - (w - d) + 1), min(d, E.second + c));
							add += dfs(a, b - 1, c, d);
							dp[a][b][c][d] = max(dp[a][b][c][d], add);
						}
					}
					//choose c
					{
						can = E.second + c + 1;
						if (c + 1 <= can&&can <= d){
							add = rect(max(a, E.first - (h - b) + 1), min(b, E.first + a), can, can);
							add += dfs(a, b, c + 1, d);
							dp[a][b][c][d] = max(dp[a][b][c][d], add);
						}
					}
					//choose d
					{
						can = E.second - (w - d);
						if (c <= can&&can <= d - 1){
							add = rect(max(a, E.first - (h - b) + 1), min(b, E.first + a), can, can);
							add += dfs(a, b, c, d - 1);
							dp[a][b][c][d] = max(dp[a][b][c][d], add);
						}
					}
				}
			}
		}
	}
	
	int ans=dfs(0, h - 1, 0, w - 1);
	cout << ans << endl;
	return 0;
}