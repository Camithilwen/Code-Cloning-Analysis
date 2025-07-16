#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7, maxN = 1e5 + 13;
int n, x, dp[maxN], dpw[maxN];
vector<int> vec;
int pw (int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % mod)
	if (b & 1)
	    ret = 1ll * ret * a % mod;
    return ret;
}

					
int32_t main () {
    cin >> n >> x;
    int cur = 1;
    for (int i = 0; i < n; i++) {
	int a;
	cin >> a;
	if (a <= x)
	    vec.push_back(a);
	cur = (cur * (i + 1)) % mod;
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i <= n; i++)
	dpw[i] = pw(i, mod - 2);
    
    for (int i = 0; i <= x; i++) {
	int pos = upper_bound(vec.begin(), vec.end(), i) - vec.begin();
	if (pos == 0)
	    dp[i] = i;
	for (int j = 0; j < pos; j++) {
	    //cout << i << " " << vec[j] << " " << dp[i % vec[j]] << endl;
	    dp[i] = (dp[i] + dpw[pos] * dp[i % vec[j]]) % mod;
	}
	
	//cout << i << " " << pos << " " << dp[i] << endl;
    }
    
    //cout << solve(x, n) << " " << cur  << endl;
    cout << 1ll * dp[x] * cur % mod << endl;
}
