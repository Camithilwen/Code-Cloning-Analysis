#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define REPI(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)
#define ALL(v) (v).begin(), (v).end()

#define dump(x) (cout << #x << " = " << x << endl)
#define dump2(x, y) (cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl)
#define dump3(x, y, z) (cout << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", "<< z << ")" << endl)

typedef long long ll;
typedef pair<int, int> pii;

#define VACANT 0
#define BLOCK 1
#define START 2
#define GOAL 3

#define INF (1<<29)
#define MAX 21

int w, h;
int brd[MAX][MAX];
int ans;

int sx, sy;
int gx, gy;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int depth, int y, int x)
{
/*
rep(j, h) {
	rep(i, w) {
		char ch;
		switch(brd[j][i]) {
		case VACANT: ch = '.'; break;
		case BLOCK: ch = '#'; break;
		}
		if (j == y && i == x)
			ch = 'X';
		if (j == gy && i == gx)
			ch = 'G';
		printf("%c ", ch);
	}
	puts("");
}
puts("-------");
*/
	if (depth >= 10) return;

	rep(i, 4) {
		REP(t, 1, max(w, h)) {
			int ny = y+dy[i]*t, nx = x+dx[i]*t;
			if (ny == gy && nx == gx) {
				ans = min(ans, depth+1);
				return;
			}
			if (!(0 <= ny && ny < h)) goto NEXT;
			if (!(0 <= nx && nx < w)) goto NEXT;
			if (t == 1 && brd[ny][nx] == BLOCK) goto NEXT;
			if (brd[ny][nx] == BLOCK) {
				int ty = ny-dy[i], tx = nx-dx[i];
				brd[ny][nx] = VACANT;
				dfs(depth+1, ty, tx);
				brd[ny][nx] = BLOCK;
				break;
			}
		}
NEXT:
		;
	}
}

int main(void)
{
	while (cin >> w >> h, w|h) {
		rep(j, h)
			rep(i, w) {
				cin >> brd[j][i];
				if (brd[j][i] == START) {
					brd[j][i] = VACANT;
					sx = i, sy = j;
				} else if (brd[j][i] == GOAL) {
					brd[j][i] = VACANT;
					gx = i, gy = j;
				}
			}

		ans = INF;
		dfs(0, sy, sx);
		printf("%d\n", ans==INF?-1:ans);
	}
	return 0;
}