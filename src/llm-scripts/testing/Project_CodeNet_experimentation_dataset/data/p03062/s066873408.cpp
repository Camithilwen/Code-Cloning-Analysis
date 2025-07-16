#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[int(1e5+10)]; 
ll dp[100010][2];
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i];
	dp[0][0] = 0;
	dp[0][1] = -(1LL<<60);
	rep(i,n) {
		dp[i+1][0]=max(dp[i][0]+a[i],dp[i][1]-a[i]);
		dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
	}
	cout << dp[n][0] << endl;
	return 0;
}