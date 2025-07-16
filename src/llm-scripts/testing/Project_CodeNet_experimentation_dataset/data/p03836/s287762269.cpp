#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;

	int dy = ty - sy;
	int dx = tx - sx;

	REP(i, dy) cout << 'U';
	REP(i, dx) cout << 'R';
	REP(i, dy) cout << 'D';
	REP(i, dx) cout << 'L';
	cout << 'L';
	REP(i, dy + 1) cout << 'U';
	REP(i, dx + 1) cout << 'R';
	cout << 'D';
	cout << 'R';
	REP(i, dy + 1) cout << 'D';
	REP(i, dx + 1) cout << 'L';
	cout << 'U';
	cout << '\n';
    return 0;
}
