#include <bits/stdc++.h>
#define All(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll prim(int n, vector<vector<pll>> &edge)
{
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	vector<bool> used(n, false);
	// 点0からスタート
	pq.push(pll(0, 0));
	ll all_len = 0;
	while (!pq.empty())
	{
		ll now = pq.top().second, len = pq.top().first;
		pq.pop();
		if (used[now])
			continue;
		used[now] = true;
		all_len += len;
		for (int i = 0; i < edge[now].size(); i++)
		{
			ll next_len = edge[now][i].first;
			ll next = edge[now][i].second;
			pq.push(pll(next_len, next));
		}
	}
	return all_len;
}

int main()
{
	int N;
	cin >> N;
	vector<pll> xy, yx;
	map<pll, ll> mp;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		cin >> x >> y;
		if(!mp.count(pll(x, y))) {
			mp[pll(x, y)] = cnt;
			xy.push_back(pll(x, y));
			yx.push_back(pll(y, x));
			cnt++;
		}
	}
	sort(All(xy));
	sort(All(yx));

	vector<vector<pll>> edge(cnt);

	for (int i = 0; i < cnt - 1; i++)
	{
		auto now = xy[i];
		int nowp = mp[now];
		
		auto next = xy[i + 1];
		int nexp = mp[next];
		edge[nowp].push_back(pll(min(llabs(now.first - next.first), llabs(now.second - next.second)), nexp));
		edge[nexp].push_back(pll(min(llabs(now.first - next.first), llabs(now.second - next.second)), nowp));
	}
	for (int i = 0; i < cnt - 1; i++)
	{
		auto now = yx[i];
		int nowp = mp[pll(now.second, now.first)];
		
		auto next = yx[i + 1];
		int nexp = mp[pll(next.second, next.first)];
		edge[nowp].push_back(pll(min(llabs(now.first - next.first), llabs(now.second - next.second)), nexp));
		edge[nexp].push_back(pll(min(llabs(now.first - next.first), llabs(now.second - next.second)), nowp));
	}
	cout << prim(cnt, edge) << endl;
}