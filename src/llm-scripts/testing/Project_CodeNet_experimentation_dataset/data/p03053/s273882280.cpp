#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>>grid(h+2, vector<int>(w+2,0));
	queue<pair<int, int>>black;
	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			char x;
			cin >> x;
			if (x == '.')grid.at(i).at(j) = 1e9;
			else black.push({ i, j });
		}
	}
	while (black.size() >= 1) {
		int x = black.front().first;
		int y = black.front().second;
		if (grid.at(x - 1).at(y) > grid.at(x).at(y) + 1) {
			grid.at(x - 1).at(y) = grid.at(x).at(y) + 1;
			black.push({ x - 1,y });
		}
		if (grid.at(x + 1).at(y) > grid.at(x).at(y) + 1) {
			grid.at(x + 1).at(y) = grid.at(x).at(y) + 1;
			black.push({ x + 1,y });
		}
		if (grid.at(x).at(y - 1) > grid.at(x).at(y) + 1) {
			grid.at(x).at(y - 1) = grid.at(x).at(y) + 1;
			black.push({ x,y - 1 });
		}
		if (grid.at(x).at(y + 1) > grid.at(x).at(y) + 1) {
			grid.at(x).at(y + 1) = grid.at(x).at(y) + 1;
			black.push({ x,y + 1 });
		}
		black.pop();
	}
	int ans = 0;
	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			ans = max(ans, grid.at(i).at(j));
		}
	}
	cout << ans << endl;
}