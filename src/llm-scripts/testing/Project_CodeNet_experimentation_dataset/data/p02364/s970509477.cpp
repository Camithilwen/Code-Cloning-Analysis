#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <string>
#include <ctype.h>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <functional>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 1145141919
#define ll long long
//#define scanf scanf_s

int v, e;
struct edge{ int from, to, cost; };
edge ed[100001];
int par[10001];

bool comp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}

int find(int x)
{
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	par[x] = y;
}

bool same(int x, int y)
{
	return (find(x) == find(y));
}

int main()
{
	cin >> v >> e;
	int a, b, c;
	REP(i, e)
	{
		cin >> a >> b >> c;
		ed[i] = { a, b, c };
	}
	sort(ed, ed + e, comp);
	int sum = 0;
	REP(i, 10001) par[i] = i;
	REP(i, e)
	{
		if (!same(ed[i].from,ed[i].to))
		{
			unite(ed[i].from, ed[i].to);
			sum += ed[i].cost;
		}
	}
	cout << sum << endl;
	return 0;
}