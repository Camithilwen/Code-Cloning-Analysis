#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int k;
	cin >> k;
	vector<vector<int>> chess(8, vector<int>(8));
	auto ok = [&](const vector<vector<int>> &newChess) {
		REP(i, 8) {
			int cnt = 0;
			REP(j, 8) {
				cnt += newChess[i][j];
				if (cnt > 1) {
					return false;
				}
			}
		}
		REP(j, 8) {
			int cnt = 0;
			REP(i, 8) {
				cnt += newChess[i][j];
				if (cnt > 1) {
					return false;
				}
			}
		}
		REP(i, 8) {
			int cnt = 0;
			REP(j, 8) {
				if (i + j == 8) break;
				cnt += newChess[i + j][j];
				if (cnt > 1) {
					return false;
				}
			}
		}
		REP(i, 8) {
			int cnt = 0;
			REP(j, 8) {
				if (i - j < 0) break;
				cnt += newChess[i - j][j];
				if (cnt > 1) {
					return false;
				}
			}
		}
		REP(j, 8) {
			int cnt = 0;
			REP(i, 8) {
				if (j + i == 8) break;
				cnt += newChess[i][j + i];
				if (cnt > 1) {
					return false;
				}
			}
		}
		REP(j, 8) {
			int cnt = 0;
			REP(i, 8) {
				if (j + i == 8) break;
				cnt += newChess[7 - i][j + i];
				if (cnt > 1) {
					return false;
				}
			}
		}
		return true;
	};
	REP(i, k) {
		int r, c;
		cin >> r >> c;
		chess[r][c] = 1;
	}
	vector<int> v(8);
	REP(i, 8) { v[i] = i; }

	do {
		vector<vector<int>> newChess = chess;
		REP(i, 8) {
			newChess[i][v[i]] = 1;
		}
		if (ok(newChess)) {
			REP(i, 8) {
				REP(j, 8) {
					if (newChess[i][j]) {
						cout << 'Q';
					} else {
						cout << '.';
					}
				}
				cout << endl;
			}
		}
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}

