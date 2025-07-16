#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>

// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#endif
// END CUT HERE 

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) begin(v), end(v)
#define REV(v) rbegin(v), rend(v)
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define MP make_pair
#define MT make_tuple
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int w, h;

const int N = 20;
int v[N][N];

inline bool in(int x, int y){
	return  0 <= x && x < w && 0 <= y && y < h;
}

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int ans;
void dfs(int i, int x, int y){
	if (ans < i) return;
	if (i == 10) return;

	rep(d, 4){
		int nx = x + dx[d], ny = y + dy[d];
		if (in(nx, ny) && v[ny][nx] == 1) continue;
		while (in(nx, ny) && v[ny][nx] == 0){
			nx += dx[d], ny += dy[d];
		}
		if (!in(nx, ny)) continue;
		if (v[ny][nx] == 3){
			ans = min(ans, i + 1);
			break;
		}
		else{
			v[ny][nx] = 0;
			dfs(i + 1, nx - dx[d], ny - dy[d]);
			v[ny][nx] = 1;
		}
	}
}

int main(){
	while (cin >> w >> h, w){
		rep(i, h) rep(j, w) cin >> v[i][j];
		ans = 100;
		rep(i, h) rep(j, w) if (v[i][j] == 2) v[i][j] = 0, dfs(0, j, i);
		cout << (ans == 100 ? -1 : ans) << endl;
	}

	return 0;
}