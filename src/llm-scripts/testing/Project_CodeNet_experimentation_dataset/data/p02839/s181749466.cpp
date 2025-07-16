#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[101][101], b[101][101];
bitset<20001> f[101][101];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> b[i][j];
	f[1][1].set(10000);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int v1 = a[i][j] - b[i][j];
			int v2 = b[i][j] - a[i][j];
			if (v1 >= 0)
			{
				f[i + 1][j] |= (f[i][j] << v1);
				f[i][j + 1] |= (f[i][j] << v1); 
			}	
			else
			{
				v1 = -v1;
				f[i + 1][j] |= (f[i][j] >> v1);
				f[i][j + 1] |= (f[i][j] >> v1); 
			}	
			if (v2 >= 0)
			{
				f[i + 1][j] |= (f[i][j] << v2);
				f[i][j + 1] |= (f[i][j] << v2);
			}
			else
			{
				v2 = -v2;
				f[i + 1][j] |= (f[i][j] >> v2);
				f[i][j + 1] |= (f[i][j] >> v2);
			}	
		}
	int ans = 1e9;
	for (int i = 0; i <= 20000; i++)
		if (f[n][m].test(i))
		{       
			int v1 = i + a[n][m] - b[n][m];
			int v2 = i + b[n][m] - a[n][m];
			ans = min(ans, min(abs(v1 - 10000), abs(v2 - 10000)));
		} 
	cout << ans;	
}