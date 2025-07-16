#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n;
int h[N], e[N], ne[N], idx;
int match[N];
bool st[N];
PII point[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int u)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = true;
			if (match[j] == 0 || find(match[j]))
			{
				match[j] = u;
				return true;
			}
		}
	}
	
	return false;
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> point[i].F >> point[i].S;
	for (int i = n + 1; i <= 2 * n; i ++ ) cin >> point[i].F >> point[i].S;
	
	for (int i = 1; i <= n; i ++ )
		for (int j = n + 1; j <= 2 * n; j ++ )
			if (point[i].F < point[j].F && point[i].S < point[j].S)
				add(i, j);
				
	int res = 0;
	for (int i = 1; i <= n; i ++ )
	{
		memset(st, 0, sizeof st);
		if (find(i)) res ++ ;
	}
	cout << res << endl;
	return 0;
}