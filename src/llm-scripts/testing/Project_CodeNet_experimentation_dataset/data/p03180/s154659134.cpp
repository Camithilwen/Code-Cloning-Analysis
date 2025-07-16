#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int compat[n][n];
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			cin >> compat[q][w];
		}
	}
	ll dp[1<<n];
	for (int q = 0; q < (1<<n); q++)
	{
		dp[q] = 0;
		for (int w = 0; w < n; w++)
		{
			if ((q & (1<<w)) == 0)
			{
				continue;
			}
			for (int e = w+1; e < n; e++)
			{
				if ((q & (1<<e)) != 0)
				{
					dp[q] += compat[w][e];
				}
			}
		}
	}
	for (int q = 1; q < (1<<n); q++)
	{
		for (int w = q; w > 0; w = (w-1) & q)
		{
			dp[q] = max(dp[q], dp[w] + dp[w ^ q]);
		}
	}
	cout << dp[(1<<n)-1] << "\n";
	return 0;
}
