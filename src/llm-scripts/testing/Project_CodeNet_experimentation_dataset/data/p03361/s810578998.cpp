#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> dy = { 0,1,0,-1 };
vector<int> dx = { 1,0,-1,0 };

int main() {

	int h, w; cin >> h >> w;
	vector<vector<char>> c(h + 2, vector<char>(w + 2, 'e'));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> c[i][j];
		}		
	}
	bool can = true;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			bool tmpCan = false;
			if (c[i][j] == '#') {
				for (int k = 0;  k < 4;  k++) {
					if (c[i + dy[k]][j + dx[k]] == '#') {
						tmpCan = true;
					}
				}
				if (!tmpCan) can = false;
			}			
		}
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}