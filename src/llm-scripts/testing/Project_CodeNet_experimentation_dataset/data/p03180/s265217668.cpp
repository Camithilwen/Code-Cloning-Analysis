#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 100005;
ll val[1<<16];
ll dp[1<<16];
ll solve(int mask) {
	if (~dp[mask]) {
		return dp[mask];
	}
	ll mx = -1e18;
	int low = mask & (mask);
	for (int s = mask ; s; s = (s - 1) & mask) {
		if (!(s & low))continue;
		mx = max(mx, solve(mask ^ s) + val[s]);
	}
	return dp[mask] = mx;
}
void go() {
	int n;
	cin >> n;
	f(n) {
		fr(j,0,n) {
			int x;
			cin >> x;
			if (i <= j)continue;
			for (int k = 0 ; k < (1<<n) ; k++) {
				if ((k & (1<< i)) && (k & (1<<j))) {
					val[k] += x;
				}
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	cout << solve((1 << n) - 1) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}