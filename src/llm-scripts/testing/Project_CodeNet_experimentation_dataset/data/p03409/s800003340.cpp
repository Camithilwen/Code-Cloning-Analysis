#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

struct EdgeMF
{
	int to;
	ll capacity;
	int reverse;
};

void addEdgeForFlow(vector<vector<EdgeMF>>& G, int from, int to, ll capacity, ll reverseCapacity)
{
	G[from].push_back({ to, capacity, (int)G[to].size() });
	G[to].push_back({ from, reverseCapacity, (int)G[from].size() - 1 });
}

ll dfsForFlow(vector<vector<EdgeMF>>& G, vector<bool>& used, int u, int t, ll f)
{
	if (u == t)
	{
		return f;
	}

	used[u] = true;
	for (auto& e : G[u])
	{
		if (used[e.to] || e.capacity <= 0)
		{
			continue;
		}

		auto d = dfsForFlow(G, used, e.to, t, min(f, e.capacity));
		if (d > 0)
		{
			e.capacity -= d;
			G[e.to][e.reverse].capacity += d;
			return d;
		}
	}

	return 0;
}

ll calcMaxFlow(vector<vector<EdgeMF>>& G, int s, int t)
{
	auto f = 0ll;
	while (true)
	{
		vector<bool> used((int)G.size());
		auto d = dfsForFlow(G, used, s, t, LLONG_MAX);
		if (d <= 0)
		{
			break;
		}
		f += d;
	}

	return f;
}


int main()
{
	int N;
	cin >> N;
	vector<int> x(2 * N);
	vector<int> y(2 * N);
	for (auto i = 0; i < 2 * N; ++i)
	{
		cin >> x[i] >> y[i];
	}

	vector<vector<EdgeMF>> G(2 * N + 2);
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = N; j < 2 * N; ++j)
		{
			if (x[i] < x[j] && y[i] < y[j])
			{
				addEdgeForFlow(G, i, j, 1, 0);
			}
		}
	}
	int s = 2 * N;
	int t = s + 1;
	for (auto i = 0; i < N; ++i)
	{
		addEdgeForFlow(G, s, i, 1, 0);
		addEdgeForFlow(G, i + N, t, 1, 0);
	}

	cout << calcMaxFlow(G, s, t) << endl;

	return 0;
}