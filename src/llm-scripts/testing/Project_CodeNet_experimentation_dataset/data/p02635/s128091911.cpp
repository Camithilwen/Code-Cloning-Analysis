#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
typedef long long ll;
const ll mod = 998244353;
int tot, K;
char s[maxn];
int a[maxn];
ll f[maxn][maxn][maxn];
ll ans;
inline ll norm(const ll & x) { return x >= mod ? x - mod : x;}
int main()
{
	scanf("%s%d", s + 1, &K);
	K = min(K, 300);
	int len = strlen(s + 1);
	reverse(s + 1, s + len + 1); 
	int cur = 0;
	for(int i = 1; i <= len; ++i)
		if(s[i] == '0')
		{
			a[++tot] = cur;
			cur = 0;
		}
		else
			++cur;
	a[++tot] = cur;
	f[0][0][0] = 1;
	for(int i = 1; i <= tot; ++i)
		for(int k = 0; k <= K; ++k)
		{
			for(int j = k; ~j; --j)
				f[i][j][k] = norm(f[i - 1][j][k] + f[i][j + 1][k]);
			for(int j = 0; j <= k; ++j)
			{
				/*
				for(int jd = j; jd <= k; ++jd)
					f[i][j][k] = (f[i][j][k] + f[i - 1][jd][k]) % mod;
				*/
				int lim = min(j, a[i]);
				for(int jd = 1; jd <= lim; ++jd)
					f[i][j][k] = norm(f[i][j][k] + f[i - 1][j - jd][k - jd]);
			}
		}
	for(int k = 0; k <= K; ++k)
		ans = norm(ans + f[tot][0][k]);
	cout << ans << endl;
	return 0;
}
	