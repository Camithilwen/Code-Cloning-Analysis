#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 18;

int n;
int LOG[1 << MAXN];

ll ans;
ll f[2][1 << MAXN][MAXN + 1];
ll g[2][1 << MAXN][MAXN + 1];

string S,s,t;

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

int main()
{
	cin >> n >> S;
	LOG[0] = -1;
	for (int i = 1;i < (1 << n);i++)
		LOG[i] = LOG[i >> 1] + 1;
	s = S.substr(0,n);
	reverse(S.begin(),S.end());
	t = S.substr(0,n);
	f[0][0][0] = 1;
	for (int j = 0;j <= n;j++)
	{
		memset(f[~j & 1],0,sizeof(f[~j & 1]));
		memset(g[~j & 1],0,sizeof(g[~j & 1]));
		for (int i = 0,I = 0;i < (1 << n);I = popcount(++i))
		{
			if (j > I)
				continue;
			for (int k = 0;k < n;k++)
			{
				if (f[j & 1][i][k])
				{
					for (int l = LOG[i] + 1;l < n;l++)
						if (t[l] == s[I])
							f[~j & 1][i | (1 << l)][k + (l == k)] += f[j & 1][i][k];
					if (k == LOG[i] + 1)
					{
						for (int l = k + 1;l < n;l++)
							if (t[l] == s[I])
								g[j & 1][i | (1 << l)][k + (l == k)] += f[j & 1][i][k];
					}
					if (t[k] == s[I])
					{
						int K = k + 1;
						while (K < n && (i >> K & 1))
							K++;
						int el = LOG[i] + 1 + (LOG[i] + 1 == k);
						if (K > el)
							g[j & 1][i | (1 << k)][el] += f[j & 1][i][k];
						else
							f[j & 1][i | (1 << k)][K] += f[j & 1][i][k];
					}
				}
				if (g[j & 1][i][k])
				{
					for (int l = LOG[i] + 1;l < n;l++)
						if (t[l] == s[I])
							g[j & 1][i | (1 << l)][k] += g[j & 1][i][k];
					if (t[k] == s[I])
					{
						int K = k + 1;
						while (K < n && (i >> K & 1))
							K++;
						int el = LOG[i] + 1 + (LOG[i] + 1 == k);
						if (K >= el)
							f[~j & 1][i | (1 << k)][el] += g[j & 1][i][k];
						else
							g[~j & 1][i | (1 << k)][K] += g[j & 1][i][k];
					}
				}
			}
		}
		ans += f[j & 1][(1 << n) - 1][n];
	}
	cout << ans << endl; 
	return 0;
} 