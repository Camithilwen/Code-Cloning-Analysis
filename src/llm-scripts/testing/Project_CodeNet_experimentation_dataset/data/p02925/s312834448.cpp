#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1000010, M = 1010;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N], st[N];
int g[M][M], match[M][M];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int top_sort()
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= m; i ++ )
		if (!d[i])
		{
			q[ ++ tt] = i;
			st[i] = 1;
		}
	
	while (hh <= tt)
	{
		int t = q[hh ++ ];
		
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if ( -- d[j] == 0)
			{
				q[ ++ tt] = j;
				st[j] = st[t] + 1;
			}
		}
	}
	
	int res = 0;
	for (int i = 1; i <= m; i ++ )
		if (!st[i]) return -1;
		else res = max(res, st[i]);
	
	return res;
}

int main()
{
	memset(h, -1, sizeof h);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < n - 1; j ++ )
		{
			int a = i, b;
			scanf("%d", &b);
			g[i][j] = b;
			
			if (match[a][b]) continue;
			match[a][b] = match[b][a] = ++ m;
		}
		
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < n - 2; j ++ )
		{
			int a = match[i][g[i][j]], b = match[i][g[i][j + 1]];
			d[b] ++ ;
			add(a, b);
		}
		
	printf("%d\n", top_sort());
	return 0;
}