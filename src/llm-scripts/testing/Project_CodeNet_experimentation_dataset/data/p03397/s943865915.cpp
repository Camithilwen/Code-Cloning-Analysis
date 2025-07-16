#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi totor<int>
#define vl totor<ll>
#define rep(i, x, y) for(register int i = x; i <= y; i ++)
#define rrep(i, x, y) for(register int i = x; i >= y; i --)
#define eps 1e-15
#define lb(x) x & -x
#define sz(x) (x).size()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 + 7;
char ch[300010];
int n;
ll k, dp[300010][5][3];
int main()
{
	scanf("%s", ch);
	n = strlen(ch);
	dp[0][2][0] = 1;
	rep(i, 0, n - 1)
	{
        if (ch[i] != '0')
        {
            (dp[i + 1][4][1] += dp[i][4][1]) %= mod;
            (dp[i + 1][4][1] += dp[i][3][1]) %= mod;
            (dp[i + 1][3][1] += dp[i][2][0]) %= mod;
            (dp[i + 1][3][1] += dp[i][2][1]) %= mod;
            (dp[i + 1][2][0] += dp[i][1][0]) %= mod;
            (dp[i + 1][2][1] += dp[i][1][1]) %= mod;
            (dp[i + 1][1][0] += dp[i][0][0]) %= mod;
        }
        if (ch[i] != '1')
        {
            (dp[i + 1][4][1] += dp[i][4][1]) %= mod;
            (dp[i + 1][2][1] += dp[i][3][1]) %= mod;
            (dp[i + 1][1][0] += dp[i][2][0]) %= mod;
            (dp[i + 1][1][1] += dp[i][2][1]) %= mod;
            (dp[i + 1][0][0] += dp[i][1][0]) %= mod;
            (dp[i + 1][2][1] += dp[i][1][1]) %= mod;
            (dp[i + 1][1][0] += dp[i][0][0]) %= mod;
        }
    }
    cout << (dp[n][3][1] + dp[n][4][1]) % mod << endl;
    return 0;
}
