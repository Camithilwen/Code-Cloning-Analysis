#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

queue<int>Q;
int z[100][100], x[100][100], sum; char a;

void BFS(int col,int x1,int y1) {
	Q.push(x1 * 100 + y1);
	x[x1][y1] = col;
	int a, b;
	while (!Q.empty()) {
		a = Q.front() / 100;
		b = Q.front() % 100;
		if (z[a + 1][b] == 1 && x[a + 1][b] == 0) {
			Q.push(Q.front() + 100);
			x[a + 1][b] = col;
		}
		if (z[a - 1][b] == 1 && x[a - 1][b] == 0) {
			Q.push(Q.front() - 100);
			x[a - 1][b] = col;
		}
		if (z[a][b + 1] == 1 && x[a][b + 1] == 0) {
			Q.push(Q.front() + 1);
			x[a][b + 1] = col;
		}
		if (z[a][b - 1] == 1 && x[a][b - 1] == 0) {
			Q.push(Q.front() - 1);
			x[a][b - 1] = col;
		}
		Q.pop();
	}
}

int main() {
	while (cin >> a) {
		if (a == '1') { z[1][1] = 1; }
		sum = 0;
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 12; j++) {
				if (i + j != 2) {
					cin >> a; if (a == '1') { z[i][j] = 1; }
				}
			}
		}
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 12; j++) {
				if (x[i][j] == 0 && z[i][j] == 1) {
					sum++;
					BFS(sum, i, j);
				}
			}
		}
		cout << sum << endl;
		memset(x, 0, sizeof(x));
		memset(z, 0, sizeof(z));
	}
}