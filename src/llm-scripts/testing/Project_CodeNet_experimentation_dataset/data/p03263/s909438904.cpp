
// D - Make Them Even

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;


struct Cell {
	int y;
	int x;
	int c;
};

struct Move {
	int y1;
	int x1;
	int y2;
	int x2;
};

int field[500][500];
Cell cells[500 * 500];

int main() {
	int H, W;
	cin >> H >> W;

	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			cin >> field[i][j];
		}
	}

	int k = 0;
	for (int i=0; i<H; i++) {
		if (i % 2 == 0) {
			for (int j=0; j<W; j++) {
				cells[k] = {i, j, field[i][j]};
				k++;
			}
		} else {
			for (int j=W-1; j>=0; j--) {
				cells[k] = {i, j, field[i][j]};
				k++;
			}
		}
	}

	int N = 0;
	vector<Move> ans;
	for (int i=0; i<H*W-1; i++) {
		if (cells[i].c % 2 == 1) {
			ans.push_back(Move{cells[i].y, cells[i].x, cells[i+1].y, cells[i+1].x});
			cells[i+1].c++;
			N++;
		}
	}

	cout << N << endl;
	for (Move a : ans) {
		cout << a.y1 + 1 << " " << a.x1 + 1 << " " << a.y2 + 1 << " " << a.x2 + 1 << endl;
	}

	return 0;
}