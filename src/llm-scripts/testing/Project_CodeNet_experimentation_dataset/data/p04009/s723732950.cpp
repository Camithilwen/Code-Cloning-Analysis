#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 105;

char sl[nax][nax];
// int pref[nax][nax];
int dp[nax][nax][nax], old[nax][nax][nax];
int fixX[nax][nax], fixY[nax][nax];

/*int getSum(int x1, int y1, int x2, int y2) {
	if(x1 > x2) return 0;
	if(y1 > y2) return 0;
	if(x1 == x2) return fixX[x1][y2] - (y1 ? fixX[x1][y1-1] : 0);
	if(y1 == y2) return fixY[y1][x2] - (x1 ? fixY[y1][x1-1] : 0);
	assert(false);
}*/

int sumY(int y, int x1, int x2) {
	if(x1 > x2) return 0;
	maxi(x1, 0);
	mini(x2, nax - 1);
	return fixY[y][x2] - (x1 ? fixY[y][x1-1] : 0);
}
int sumX(int x, int y1, int y2) {
	if(y1 > y2) return 0;
	maxi(y1, 0);
	mini(y2, nax - 1);
	return fixX[x][y2] - (y1 ? fixX[x][y1-1] : 0);
}


int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	int ex, ey;
	REP(y, h) {
		scanf("%s", sl[y]);
		REP(x, w) {
			if(x) fixY[y][x] += fixY[y][x-1];
			if(y) fixX[x][y] += fixX[x][y-1];
			//if(x) pref[x][y] += pref[x-1][y];
			//if(y) pref[x][y] += pref[x][y-1];
			//if(x && y) pref[x][y] -= pref[x-1][y-1];
			if(sl[y][x] == 'E') {
				ex = x;
				ey = y;
			}
			else if(sl[y][x] == 'o') {
				//++pref[x][y];
				++fixX[x][y];
				++fixY[y][x];
			}
		}
	}
	int ans = 0;
	
	REP(a,nax)REP(b,nax)REP(c,nax) dp[a][b][c] = old[a][b][c] = -inf;
	
	dp[ex][ey][ey] = 0;
	
	FORD(x1, ex, 0) {
		if(x1 != ex) REP(a,nax)REP(b,nax)REP(c,nax) {
			old[a][b][c] = dp[a][b][c];
			dp[a][b][c] = -inf;
		}
		FOR(x2, ex, w - 1) FORD(y1, ey, 0) FOR(y2, ey, h - 1) {
			int & me = dp[x2][y1][y2];
			//if(y2 < h - ey + y1) {
			//	puts("a");
			if(y1 >= (y2 - ey))
				maxi(me, dp[x2][y1+1][y2] + sumY(y1, max(x1, x2 - ex), min(x2, w - 1 - (ex - x1))));
			if(y2 < h - (ey - y1))
				maxi(me, dp[x2][y1][y2-1] + sumY(y2, max(x1, x2 - ex), min(x2, w - 1 - (ex - x1))));
			
			//if(x2 < w - ex + x1) {
			//	puts("b");
			if(x2 < w - (ex - x1))
				maxi(me, (x2 ? dp[x2-1][y1][y2] : 0) + sumX(x2, max(y1, y2 - ey), min(y2, h - 1 - (ey - y1))));
			if(x1 >= (x2 - ex))
				maxi(me, old[x2][y1][y2] + sumX(x1, max(y1, y2 - ey), min(y2, h - 1 - (ey - y1))));
			
			//printf("%d,%d,%d,%d -> %d\n", x1, x2, y1, y2, me);
			maxi(ans, me);
		}
	}
	
	printf("%d\n", ans);
	
	/*FOR(x1, 0, ex) {
		int x2 = ex - 1;
		while(x2 + 1 < w && x2 + 1 + (ex - x1) < w) ++x2;
		if(x2 == ex - 1) continue;
		FOR(y1, 0, ey) {
			int y2 = ey - 1;
			while(y2 + 1 < h && y2 + 1 + (ey - y1) < h) ++y2;
			if(y2 == ey - 1) continue;
			int maybe = pref[x2][y2];
			if(x1) maybe -= pref[x1-1][y2];
			if(y1) maybe -= pref[x2][y1-1];
			if(x1 && y1) maybe += pref[x1-1][y1-1];
			//printf("%d %d %d %d\n", x1, x2, y1, y2);
			maxi(ans, maybe);
		}
	}
	printf("%d\n", ans); */
	return 0;
}
