// besmellah
#include <bits/stdc++.h>

using namespace std;
typedef long long int64;
typedef pair<int,int> pii;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e4+10;
const int64 MO = 1000000007;
const int64 IN = 1000000000;

int d;
string s;
int dp[maxn][105];

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> d;
	for (int i = 0; i < maxn; i++)
		for (int t = 0; t < 105; t++)
			dp[i][t] = 0;

	dp[0][0] = 1;
	for (int i = 0; i <= 9; i++)
		dp[1][i % d]++;
	for (int i = 2; i <= sz(s); i++)
		for (int k = 0; k < d; k++)
			for (int t = 0; t <= 9; t++)
				dp[i][(t + k) % d] = (dp[i][(t + k) % d] + dp[i - 1][k]) % MO;
	
	int cur = 0;
	int ans = -1;
	for (int i = 0; i < sz(s); i++) {
		for (int t = 0; t < s[i] - '0'; t++) {
			int f = (cur + t) % d;
			f = (d - f) % d;
			ans = (ans + dp[sz(s) - i - 1][f]) % MO;
		}
		cur = (cur + s[i] - '0') % d;
	}
	if (cur == 0)
		ans++;
	ans = (ans + MO) % MO;
	cout << ans << "\n";
}
