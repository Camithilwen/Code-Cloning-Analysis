#include<iostream>
#include<vector>
#include<string>
using namespace std;

int tisei[12][12];
void shima(int x, int y) {
	tisei[x][y] = 0;
	if (x < 11 && tisei[x+1][y]) shima(x + 1, y);
	if (x > 0 && tisei[x - 1][y])  shima(x -1, y);
	if (y < 11 && tisei[x][y+1]) shima(x , y+1);
	if (y > 0 && tisei[x][y-1])  shima(x, y-1);
}
int main() {
	vector<int>n;
	while (1) {
		for (int a = 0; a < 12; a++) {
			string c;
			cin >> c;
			if (cin.fail())goto end;
			for (int b = 0; b < 12; b++) {
				tisei[a][b] = c[b] - 48;
			}
		}
		int s = 0;
		for (int d = 0; d < 12; d++) {
			for (int e = 0; e < 12; e++) {
				if (tisei[d][e]) { s++; shima(d, e); }
			}
		}
		n.push_back(s);
	}
end:;
	for (int j : n)cout << j << endl;
}