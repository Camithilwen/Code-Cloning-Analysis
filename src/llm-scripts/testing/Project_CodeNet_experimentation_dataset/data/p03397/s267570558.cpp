#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (int)3e5 + 17;
const int mod = (int)1e9 + 7;
const int OFFSET = 5;

int n, suff[MAXN];
string s;

void read()
{
	cin >> s;
	n = s.size();
}

int dp[MAXN][10][4];

int rec(int pos, int len, int bd)
{
	if(bd > 2)
	{
		if(bd % 2 == 0) len += (bd - 2), bd = 2;
		if(bd % 2 == 1) len += (bd - 1), bd = 1;
	}

	if(bd < 0) bd = 0;
	if(len > 4) len = 4;

	if(pos == n)
	{
		if(len > 0) return 1;
		return 0;
	}

	int &memo = dp[pos][len + OFFSET][bd];
	if(memo != -1) return memo;
	memo = 0;

	if(s[pos] == '1' || s[pos] == '?') memo = (memo + rec(pos + 1, len + 1, bd - 1)) % mod;
	if(s[pos] == '0' || s[pos] == '?') memo = (memo + rec(pos + 1, len - 1, bd + 1)) % mod; 
	return memo;
}

void solve()
{
	suff[n] = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		suff[i] = suff[i + 1];
		if(s[i] == '?') suff[i] = (2ll * suff[i + 1]) % mod;
	}

	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0, 0) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

