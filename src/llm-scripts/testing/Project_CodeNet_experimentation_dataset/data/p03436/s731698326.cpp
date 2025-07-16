#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int H, W; cin >> H >> W;
	vector<char> cs(H * W);
	REP(i, H) REP(j, W) cin >> cs[i * W + j];
	const int INF = 1e9;
	vector<int> dists(H * W, INF);
	vector<int> parents(H * W, -1);
	dists[0] = 0;
	deque<int> Q{ 0 };
	while (!Q.empty())
	{
		int v = Q.front(); Q.pop_front();
		int r = v / W, c = v % W;
		vector<int> neighbors;
		if (r > 0 && cs[v - W] == '.') neighbors.push_back(v - W);
		if (r < H - 1 && cs[v + W] == '.') neighbors.push_back(v + W);
		if (c > 0 && cs[v - 1] == '.') neighbors.push_back(v - 1);
		if (c < W - 1 && cs[v + 1] == '.') neighbors.push_back(v + 1);
		for (const int n : neighbors)
		{
			if (dists[n] > dists[v] + 1)
			{
				dists[n] = dists[v] + 1;
				parents[n] = v;
				Q.push_back(n);
			}
		}
	}
	if (dists[H * W - 1] == INF)
	{
		cout << -1 << endl;
	}
	else
	{
		vector<int> path;
		for (int v = H * W - 1; v != -1; v = parents[v])
		{
			path.push_back(v);
		}
		int ans = H * W;
		for (const char ch : cs)
		{
			if (ch == '#') --ans;
		}
		cout << ans - path.size() << endl;
	}
}