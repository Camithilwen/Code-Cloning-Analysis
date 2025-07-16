#include<iostream>
#include<algorithm>
#include<vector>

#define F first
#define S second
#define PB push_back

using namespace std;

const int MAXN = 10005;
int sz[MAXN], par[MAXN];
vector<pair<int, pair<int, int> > > e;

int getpar(int x)
{
	if(par[x] == -1)
		return x;
	return par[x] = getpar(par[x]);
}

bool add(int x, int y)
{
	x = getpar(x), y = getpar(y);
	if(x == y)
		return false;
	if(sz[x] < sz[y])
		swap(x, y);
	sz[x] += sz[y];
	par[y] = x;
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	fill(par, par + n, -1);
	fill(sz, sz + n, 1);
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		e.PB({w, {x, y}});
	}
	sort(e.begin(), e.end());
	int ans = 0;
	for(auto x : e)
		if(add(x.S.F, x.S.S))
			ans += x.F;
	cout << ans << endl;
	return 0;
}