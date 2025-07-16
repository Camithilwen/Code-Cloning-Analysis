#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define MAX 10000

vector<int> G[MAX];
int n;
bool visited[MAX];
int treeIdx[MAX], parent[MAX], lowest[MAX], treeNodeCounter;

void dfs(int curIdx, int prev)
{
	treeIdx[curIdx] = lowest[curIdx] = treeNodeCounter;
	treeNodeCounter++;

	visited[curIdx] = true;
	int next;

	for (int i = 0; i < G[curIdx].size(); ++i)
	{
		next = G[curIdx][i];
		if (!visited[next])
		{
			parent[next] = curIdx;
			dfs(next, curIdx);
			lowest[curIdx] = min(lowest[curIdx], lowest[next]);
		}
		else if (next != prev)
		{
			lowest[curIdx] = min(lowest[curIdx], treeIdx[next]);
		}
	}
}

void criticalPoints()
{
	for (int i = 0; i < n; ++i)
		visited[i] = false;
	treeNodeCounter = 1;

	dfs(0, -1);

	set<int> s;
	int np = 0;
	for (int i = 1; i < n; ++i)
	{
		int p = parent[i];
		if (0 == p) np++;
		else if (treeIdx[p] <= lowest[i])
			s.insert(p);
	}
	if (np > 1) cout << 0 << endl;
	for (auto v : s) cout << v << endl;
}

int main()
{
	int m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int s, t;
		cin >> s >> t;
		G[s].push_back(t);
		G[t].push_back(s);
	}
	criticalPoints();

	return 0;
}