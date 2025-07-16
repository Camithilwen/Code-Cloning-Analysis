// M
#include<bits/stdc++.h>
using namespace std;
const int N = 303, Mod = 998244353;
int n, k, C[N], dp[N][N][N];
inline void Add(int &a, int b)
{
	a += b;
	if (a >= Mod)
		a -= Mod;
}
int main()
{
	string S;
	cin >> S >> k;
	S = "0" + S;
	for (int i = 0; i < (int)S.size();)
	{
		int r = i + 1;
		while (r < (int)S.size() && S[r] == '1')
			r ++;
		C[n ++] = r - i - 1;
		i = r;
	}
	k = min(k, (int)S.size());
	dp[n][0][0] = 1;
	int sm = 0;
	for (int i = n - 1; ~ i; sm += C[i], i --)
		for (int j = sm; j >= 0; j --)
		{
			for (int h = 0; h <= k; h ++)
				Add(dp[i][j][h], dp[i][j + 1][h]),
				Add(dp[i][j][h], dp[i + 1][j][h]);
			for (int h = 0; h <= k; h ++)
				for (int df = 1; df <= C[i]; df ++)
					Add(dp[i][j + df][h + df], dp[i + 1][j][h]);
		}
	int tot = 0;
	for (int h = 0; h <= k; h ++)
		Add(tot, dp[0][0][h]);
	return !printf("%d\n", tot);
}
