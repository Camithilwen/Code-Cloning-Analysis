#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define rp(i,n) for(long long i=1;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
long long p = 1000000007;
vel rui(19, 1);
vel par;
int root(int ser) {
	if (par[ser] == -1) { return ser; }
	int ans = root(par[ser]);
	par[ser] = ans;
	return ans;
}
bool marge(pin a) {
	int x = root(a.first);
	int y = root(a.second);
	if (x != y) {par[x] = y;}
	return x != y;
}
signed main() {
	int n; cin >> n;
	vel x(n), y(n);
	V<pair<pin, int>> xy(n);
	V<pair<pin, int>> yx(n);
	rep(i, n) { 
		cin >> x[i] >> y[i]; 
		xy[i] = mkp(mkp(x[i], y[i]), i);
		yx[i] = mkp(mkp(y[i], x[i]), i);
	}
	sor(xy); sor(yx);
	V<pair<int, pin>> way(0);
	rep(i, n - 1) {
		int diff = xy[i + 1].first.first - xy[i].first.first;
		pin path = mkp(xy[i].second, xy[i+1].second);
		way.push_back(mkp(diff, path));
	}
	rep(i, n - 1) {
		int diff = yx[i + 1].first.first - yx[i].first.first;
		pin path = mkp(yx[i].second, yx[i + 1].second);
		way.push_back(mkp(diff, path));
	}
	sor(way);
	int ans = 0;
	par = vel(n, -1);
	rep(i, way.size()) {
		if (marge(way[i].second)) { ans += way[i].first; }
	}
	cout << ans << endl;
	return 0;
}
