#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>

using namespace std;

const long long N = 1000 * 100 + 5;
long long c[N], n, cnt = 0, is, bi, nbi;
vector < long long > graph[N];
bool mark[N], b;
void dfs(long long v)
{
	mark[v] = 1;
	for (auto u : graph[v])
	{
		if (c[u] == c[v])
		{
			b = 0;
		}
		if (!mark[u])
		{
			c[u] = 1 - c[v];
			dfs(u);
		}
	}
	return;
}
void dfs2()
{
	memset(c , -1 , sizeof c);
	for(long long i = 0; i < n; i++)
	{
		if(!mark[i])
		{
			cnt++;
			b = 1;
			c[i] = 1;
			if(graph[i].size())
			{
				dfs(i);
				if(b)
				{
					bi++;
				}
				else
				{
					nbi++;
				}
			}
			else
			{
				is++;
			}
		}
	}
	return;
}
int main()
{
	long long m;
	cin >> n >> m;
	for (long long i = 0; i < m; i++)
	{
		long long u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	dfs2();
	cout << (bi + nbi) * (bi + nbi) + bi * bi + 2 * n * is - is * is << endl;
}
