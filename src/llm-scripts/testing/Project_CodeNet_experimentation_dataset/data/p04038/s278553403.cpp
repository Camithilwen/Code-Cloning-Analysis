#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 2e3 + 20;
const int maxm = maxn * maxn + 20;
const int mod = 1e9 + 7;

int dp[maxn][maxn] , fac[maxm] , caf[maxm];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

int c(int s , int r)
{
	if(r < 0 || r > s)
		return 0;

	return 1LL * fac[s] * caf[r] % mod * caf[s - r] % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxm; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxm - 1] = bpw(fac[maxm - 1] , mod - 2);
	for(int i = maxm - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int n , k;
	cin >> n >> k;

	if(k == 1)
		return cout << 1 << endl , 0;

	dp[0][0] = 1;
	for(int j = 0; j <= n; j++)
		for(int i = 0; i <= j; i++)
		{
			mkay(dp[i + 1][j] += 1LL * dp[i][j] * (n - i) % mod * c(n * k - (k - 1) * i - j - 1 , k - 2) % mod);
			mkay(dp[i][j + 1] += dp[i][j]);
		}

	cout << dp[n][n] << endl;
}
















