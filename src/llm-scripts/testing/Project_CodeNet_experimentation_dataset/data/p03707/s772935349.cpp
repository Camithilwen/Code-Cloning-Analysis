#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 3;
int s[MAXN][MAXN], v[MAXN][MAXN], e[MAXN][MAXN], romokh[2][MAXN][MAXN];
int n, m, q;
int a1, a2, b1, b2;

void input();
void cm_romokh();
void solve();

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	input();
	return 0;
}

void input() {
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			s[i][j] = c - '0';
			//cout << s[i][j] << endl;
			if (i == 0 && j == 0) v[i][j] = (s[i][j] == 1);
			else if (i == 0) {
				v[i][j] = v[i][j - 1] + (s[i][j] == 1);
				e[i][j] = e[i][j - 1] + (s[i][j] == s[i][j - 1] && s[i][j] == 1);
			}
			else if (j == 0) {
				v[i][j] = v[i - 1][j] + (s[i][j] == 1);
				e[i][j] = e[i - 1][j] + (s[i][j] == s[i - 1][j] && s[i][j] == 1);
			}
			else {
				v[i][j] = v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1] + (s[i][j] == 1);
				e[i][j] = e[i][j - 1] + e[i - 1][j] - e[i - 1][j - 1] + (s[i][j] == 1 && s[i][j] == s[i - 1][j]) + (s[i][j] == 1 && s[i][j] == s[i][j - 1]);
			}
		}
	cm_romokh();
	//cout << romokh[1][1][2];
	while (q--) {
		cin >> a1 >> b1 >> a2 >> b2;
		if (a1 > a2) swap(a1, a2);
		if (b1 > b2) swap(b1, b2);
		a1--, a2--, b1--, b2--;
		solve();
	}
}

void cm_romokh() {
	for (int i = 1; i < n; i++) {
		romokh[0][i][0] = (s[i][0] == s[i - 1][0] && s[i][0] == 1);
		for (int j = 1; j < m; j++)
			romokh[0][i][j] = romokh[0][i][j - 1] + (s[i][j] == s[i - 1][j] && s[i][j] == 1);
	}
	for (int i = 1; i < m; i++) {
		romokh[1][0][i] = (s[0][i] == s[0][i - 1] && s[0][i] == 1);
		for (int j = 1; j < n; j++)
			romokh[1][j][i] = romokh[1][j - 1][i] + (s[j][i] == s[j][i - 1] && s[j][i] == 1);
	}
}

void solve() {
	int te = 0, tv = 1;
	if (a1 == 0 && b1 == 0) {
		tv = v[a2][b2];
		te = e[a2][b2];
	}
	else if (a1 == 0) {
		tv = v[a2][b2] - v[a2][b1 - 1];
		te = e[a2][b2] - e[a2][b1 - 1] - romokh[1][a2][b1];
	}
	else if (b1 == 0) {
		tv = v[a2][b2] - v[a1 - 1][b2];
		te = e[a2][b2] - e[a1 - 1][b2] - romokh[0][a1][b2];
	}
	else {
		tv = v[a2][b2] + v[a1 - 1][b1 - 1] - v[a1 - 1][b2] - v[a2][b1 - 1];
		te = e[a2][b2] + e[a1 - 1][b1 - 1] - e[a1 - 1][b2] - e[a2][b1 - 1];
		te -= romokh[0][a1][b2] - romokh[0][a1][b1 - 1];
		te -= romokh[1][a2][b1] - romokh[1][a1 - 1][b1];
	}
	cout << tv - te << endl;
}
