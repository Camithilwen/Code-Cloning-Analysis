#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

constexpr Int mod = 1e9+7;
Int n, x, y, z;
vector<vector<Int>> dp;

bool ok(Int w){
	Int c = 0;
	for(Int j=0; (w>>j)>0; ++j)
		if((w>>j) & 1){
			if(j+1 == z) c += 4;
			if(j+1 == z+y) c += 2;
			if(j+1 == z+y+x) c += 1;
		}
	return c != 7;
}

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> x >> y >> z;
	dp.resize(n, vector<Int>(1<<(x+y+z)));
	for(Int i=1; i<=10; ++i){
		Int t = (1<<(i-1));
		t &= (1<<(x+y+z))-1;
		++dp[0][t];
	}
	for(Int i=0; i<n-1; ++i)
		for(Int j=0; j<(1<<(x+y+z)); ++j)
			for(Int k=1; k<=10; ++k){
//				cout << i << " " << j << " " << k << "\n";
				Int t = j;
				t <<= k;
				t |= (1<<(k-1));
				t &= (1<<(x+y+z))-1;
				if(ok(t)){
					dp[i+1][t] += dp[i][j];
					dp[i+1][t] %= mod;
				}
			}
	Int ans = 1;
	for(Int i=0; i<n; ++i){
		ans *= 10;
		ans %= mod;
	}
	for(Int i=0; i<(1<<(x+y+z)); ++i){
		ans -= dp[n-1][i];
		if(ans < 0) ans += mod;
	}
	cout << ans << "\n";
}