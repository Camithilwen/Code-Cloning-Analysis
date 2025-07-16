#include <iostream>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;
const int MAXXYZ = 17;

int n,x,y,z;

inline bool hasXYZ(int a){
	return (a >> (z - 1)) & (a >> (y + z - 1)) & (a >> (x + y + z - 1)) & 1;
}

signed main(){
	ll dp[50][1 << MAXXYZ] = {};
	cin >> n >> x >> y >> z;
	dp[0][0] = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < (1 << MAXXYZ);j++){
			for(int k = 1;k <= 10;k++){
				int nxt = ((j << k) + (1 << (k - 1))) % (1 << MAXXYZ);
				if(!hasXYZ(nxt)) (dp[i + 1][nxt] += dp[i][j]) %= MOD;
			}
		}
	}
	ll ans = 1;
	for(int i = 0;i < n;i++) ans = ans * 10 % MOD;
	for(int i = 0;i < (1 << MAXXYZ);i++) ans = (ans - dp[n][i] + MOD) % MOD;
	cout << ans << endl;
}