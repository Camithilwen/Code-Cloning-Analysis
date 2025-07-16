#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
const int inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<P, int>PP;
int n;
int board[1005][1005];
void paint4(int ni, int nj) {
	board[ni][nj] = 1;
	board[ni][nj + 1] = 1;
	board[ni][nj + 2] = 3;
	board[ni][nj + 3] = 4;
	board[ni + 1][nj] = 2;
	board[ni + 1][nj + 1] = 2;
	board[ni + 1][nj + 2] = 3;
	board[ni + 1][nj + 3] = 4;
	board[ni + 2][nj] = 5;
	board[ni + 2][nj + 1] = 6;
	board[ni + 2][nj + 2] = 7;
	board[ni + 2][nj + 3] = 7;
	board[ni + 3][nj] = 5;
	board[ni + 3][nj + 1] = 6;
	board[ni + 3][nj + 2] = 8;
	board[ni + 3][nj + 3] = 8;
}
void paint(int ni, int nj, int N) {
	board[ni][nj] = 1;
	board[ni][nj + 1] = 1;
	board[ni][nj + 2] = 2;
	board[ni + 1][nj] = 3;
	board[ni + 1][nj + 2] = 2;
	board[ni + 2][nj] = 3;
	board[ni + 2][nj + 1] = 4;
	board[ni + 2][nj + 2] = 4;
	for (int i = ni; i<ni + 3; i++) {
		for (int j = nj + 3; j < nj + N; j += 2) {
			if (((j - 3) / 2) & 1) {
				board[i][j] = 5 + i % 2;
				board[i][j + 1] = 5 + i % 2;
			}
			else {
				board[i][j] = 6 + i % 2;
				board[i][j + 1] = 6 + i % 2;
			}
		}
	}
	for (int i = ni + 3; i < ni + N; i += 2) {
		for (int j = nj; j<nj + 3; j++) {
			if (((i - 3) / 2) & 1) {
				board[i][j] = 7 + j % 2;
				board[i + 1][j] = 7 + j % 2;
			}
			else {
				board[i][j] = 8 + j % 2;
				board[i + 1][j] = 8 + j % 2;
			}
		}
	}
}
bool hante() {
	set<int>S1;
	rep(i, n)if (board[i][0])S1.insert(board[i][0]);
	if (S1.size() != 4)return false;
	rep(i, n) {
		set<int>S;
		rep(j, n)if (board[i][j])S.insert(board[i][j]);
		if (S1.size() != S.size())return false;
	}
	rep(i, n) {
		set<int>S;
		rep(j, n)if (board[j][i])S.insert(board[j][i]);
		if (S1.size() != S.size())return false;
	}
	return true;

}
void disp() {
	rep(i, n) {
		rep(j, n) {
			if (board[i][j] == 0)cout << '.';
			else cout << (char)('a' + board[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
void search(int ni, int nj, int num) {
	if (ni == n) {
		if (hante())disp();
		return;
	}
	int mi = ni, mj = nj + 1;
	if (mj == n) {
		mj = 0; mi++;
	}
	if (board[ni][nj] == 0) {
		if (nj != n - 1 && board[ni][nj + 1] == 0) {
			board[ni][nj] = num;
			board[ni][nj + 1] = num;
			search(mi, mj, num + 1);
			board[ni][nj] = 0;
			board[ni][nj + 1] = 0;
		}
		if (ni != n - 1 && board[ni + 1][nj] == 0) {
			board[ni][nj] = num;
			board[ni + 1][nj] = num;
			search(mi, mj, num + 1);
			board[ni][nj] = 0;
			board[ni + 1][nj] = 0;
		}
	}
	search(mi, mj, num);
}
signed main() {
	cin >> n;

	//	search(0,0,1);

	if (n == 2)cout << -1 << endl;
	else if (n == 7) {
		string s[7] = {
			"..bcd..",
			"..bcd..",
			"hhqq.oo",
			"ii..wnn",
			"jj..wpp",
			"..akl..",
			"..akl.."
		};
		rep(i, 7)cout << s[i] << endl;
	}
	else if (n == 11) {
		string s[11] = {
			"..bcd......",
			"..bcd......",
			"hhqq.oo....",
			"ii..wnn....",
			"jj..wpp....",
			"..akl......",
			"..akl......",
			".......aabc",
			".......ddbc",
			".......abff",
			".......abgg"
		};
		rep(i, 11)cout << s[i] << endl;
	}
	else if (n % 3 == 0) {
		for (int i = 0; i<n; i += 3)paint(i, i, 3);
		disp();
	}
	else {
		rep(i, n + 1) {
			rep(j, n + 1) {
				if (5 * i + 4 * j == n) {
					for (int m = 0; m < 5 * i; m += 5)paint(m, m, 5);
					for (int m = 5 * i; m < n; m += 4)paint4(m, m);
					goto X;
				}
			}
		}
	X:;
		disp();
	}
}
