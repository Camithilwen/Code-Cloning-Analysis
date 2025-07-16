#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 100000 + 1000;

int n;
int s[4][MAXN];
int id[MAXN], rev[MAXN];
int s1, s2, f1, f2;
bool vis[MAXN];

void no()
{
	cout << "No" << endl;
	exit(0);
}

void yes()
{
	cout << "Yes" << endl;
	exit(0);
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= n; j++)
			cin >> s[i][j];

	for(int i = 1; i <= n; i++)
	{
		if(s[1][i] % 3 == 0 && s[3][i] + 1 == s[2][i] && s[2][i] + 1 == s[1][i])
			id[i] = s[1][i] / 3, rev[i] = true;
		else if(s[3][i] % 3 == 0 && s[1][i] + 1 == s[2][i] && s[2][i] + 1 == s[3][i])
			id[i] = s[3][i] / 3, rev[i] = false;
		else
			no();
	}

	// for(int i = 1; i <= n; i++)
	// 	cout << id[i] << endl;

	for(int i = 1; i <= n; i++)
		if(id[i] % 2 != i % 2)
			no();

	for(int i = 1; i <= n; i++)
		(i & 1 ? f1 : f2) ^= rev[i];

	for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			int cur = i, cnt = 0;
			do
			{
				vis[cur] = true;
				cnt++;
				cur = id[cur];
			}
			while(cur != i);
			(i & 1 ? s1 : s2) ^= ((cnt - 1) & 1);
		}

	if((s1 ^ f2) || (s2 ^ f1))
		no();

	yes();

	return 0;
}
