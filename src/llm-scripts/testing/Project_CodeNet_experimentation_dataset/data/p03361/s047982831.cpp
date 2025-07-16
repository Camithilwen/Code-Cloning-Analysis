
// C - Grid Repainting 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

bool grid[52][52];

int main() {
	int H, W;
	cin >> H >> W;

	for (int i=1; i<=H; i++) {
		for (int j=1; j<=W; j++) {
			char s;
			cin >> s;

			if (s == '#') grid[i][j] = true;
		}
	}

	string ans = "Yes";
	for (int i=1; i<=H; i++) {
		for (int j=1; j<=W; j++) {
			if (grid[i][j]) {
				if ((!grid[i+1][j]) && (!grid[i][j+1]) && (!grid[i-1][j]) && (!grid[i][j-1])) {
					ans = "No";
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}