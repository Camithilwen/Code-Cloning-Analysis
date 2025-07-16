#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;

llint h, w, Q;
llint a[2005][2005];
llint sum[2005][2005], sumw[2005][2005], sumh[2005][2005];

llint get(llint a[2005][2005], llint sx, llint sy, llint tx, llint ty)
{
	return a[tx][ty] - a[sx-1][ty] - a[tx][sy-1] + a[sx-1][sy-1];
}

int main(void)
{
	cin >> h >> w >> Q;
	char c;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> c;
			a[x][y] = c%2;
		}
	}
	
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			sum[x][y] = sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1] + a[x][y];
			sumw[x][y] = sumw[x-1][y] + sumw[x][y-1] - sumw[x-1][y-1];
			if(a[x][y]*a[x-1][y]) sumw[x][y]++;
			sumh[x][y] = sumh[x-1][y] + sumh[x][y-1] - sumh[x-1][y-1];
			if(a[x][y]*a[x][y-1]) sumh[x][y]++;
		}
	}
	
	llint sx, sy, tx, ty;
	for(int q = 0; q < Q; q++){
		cin >> sy >> sx >> ty >> tx;
		llint ans = get(sum, sx, sy, tx, ty);
		ans -= get(sumw, sx+1, sy, tx, ty);
		ans -= get(sumh, sx, sy+1, tx, ty);
		cout << ans << endl;
	}
	
	return 0;
}
