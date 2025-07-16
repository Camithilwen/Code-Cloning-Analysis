/*
	author: parv2809
*/

#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define inf 1e18
#define fo(i,y,n,inc)	for(int i=y;i<n+y;i+=inc)
#define cin(t) int t;cin>>t
#define w(t) while(t--)
#define nl cout<<endl;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ft(i) (i&(-1*i))
#define arrIn(arr,size)		for(int i=0;i<size;i++){cin>>arr[i];}
#define arrOut(arr,size,seperater)	for(int i=0;i<size;i++){cout<<arr[i]<<seperater;}
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int powmd(int a, int b) {
	if (b == 1)	return a;
	if (b == 0)	return 1;

	int half = powmd(a, b / 2);
	int ans = half * half;
	ans %= mod;
	if (b & 1) {
		ans *= a;
	}
	ans %= mod;
	return ans;
}

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int mat[16][16];
int dp[(1 << 16)], sums[(1 << 16)];

int calculate(int mask) {
	int ans = 0;
	for (int i = 0; i < 17; i++) {
		if (mask & (1 << i)) {
			for (int j = i + 1; j < 17; j++) {
				if (mask & (1 << j)) {
					ans += mat[i][j];
				}
			}
		}
	}
	return ans;
}

void pre_compute_sums() {
	for (int i = 0; i <= (1 << 16); i++) {
		sums[i] = calculate(i);
		dp[i] = inf;
	}
}

int solve(int mask) {
	if (mask == 0)
		return 0;
	if (dp[mask] != inf)
		return dp[mask];

	int s = mask;
	int ans = 0;

	while (s > 0) {
		ans = max(ans, sums[s] + solve(mask - s));
		s = (s - 1)&mask;
	}

	return dp[mask] = ans;
}

int32_t main() {

	fastIO();
	int t = 1;
	w(t) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}
		pre_compute_sums();
		cout << solve((1 << n) - 1);
		nl;
	}

	return 0;
}

// cout << "Case #" << i << ": " << answer << endl;