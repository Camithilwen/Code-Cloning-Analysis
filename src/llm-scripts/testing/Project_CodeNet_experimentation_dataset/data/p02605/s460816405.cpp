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

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint x[200005], y[200005], u[200005], v[200005];
char c[200005];
vector<P> vec[6][4000005];

llint calc(vector<P> &vec)
{
	llint ret = inf, l = -inf;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].second == -1) l = vec[i].first;
		else ret = min(ret, vec[i].first - l);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i] >> c[i];
		x[i] *= 10, y[i] *= 10;
		u[i] = x[i] + y[i], v[i] = x[i] - y[i] + 2000002;
	}
	
	for(int i = 1; i <= n; i++){
		if(c[i] == 'R') vec[0][y[i]].push_back(P(x[i], -1));
		if(c[i] == 'L') vec[0][y[i]].push_back(P(x[i], 1));
		
		if(c[i] == 'U') vec[1][x[i]].push_back(P(y[i], -1));
		if(c[i] == 'D') vec[1][x[i]].push_back(P(y[i], 1));
		
		if(c[i] == 'R') vec[2][u[i]].push_back(P(v[i], -1));
		if(c[i] == 'U') vec[2][u[i]].push_back(P(v[i], 1));
		
		if(c[i] == 'D') vec[3][u[i]].push_back(P(v[i], -1));
		if(c[i] == 'L') vec[3][u[i]].push_back(P(v[i], 1));
		
		if(c[i] == 'L') vec[4][v[i]].push_back(P(u[i], 1));
		if(c[i] == 'U') vec[4][v[i]].push_back(P(u[i], -1));
		
		if(c[i] == 'R') vec[5][v[i]].push_back(P(u[i], -1));
		if(c[i] == 'D') vec[5][v[i]].push_back(P(u[i], 1));
	}
	
	llint ans = inf;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 4000005; j++){
			sort(vec[i][j].begin(), vec[i][j].end());
			ans = min(ans, calc(vec[i][j]));
		}
	}
	
	if(ans > inf/2) cout << "SAFE" << endl;
	else cout << ans / 2 << endl;
	
	return 0;
}