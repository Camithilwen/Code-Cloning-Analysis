#include<iostream>
using namespace std;
char map[20][20];
void dfs(int i, int j) {
	map[i][j] = '0';
	if (map[i - 1][j] == '1')dfs(i - 1, j);
	if (map[i + 1][j] == '1')dfs(i + 1, j);
	if (map[i][j - 1] == '1')dfs(i, j - 1);
	if (map[i][j + 1] == '1')dfs(i, j + 1);
	return;
}
int main() {
	for (int i = 0; i <= 13; i++) {
		for (int j = 0; j <= 13; j++) {
			map[i][j] = '0';
		}
	}
	while (cin >> map[1][1]) {
		int ans = 0;
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 12; j++) {
				if (i == 1 && j == 1)continue;
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 12; j++) {
				if (map[i][j] == '1') {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}