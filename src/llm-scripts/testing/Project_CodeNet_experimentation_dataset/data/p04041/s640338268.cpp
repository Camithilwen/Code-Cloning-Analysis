#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;

int n , x , y , z;
int dp[50][1 << 18];

int main() {
	scanf("%d %d %d %d" , &n , &x , &y , &z);
	int st = (1 << (x + y + z - 1)) | (1 << (y + z - 1)) | (1 << (z - 1));
	dp[0][0] = 1;
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = (LL)ans * 10 % mod;
		for (int j = 0; j < (1 << (x + y + z)); ++j) {
			if(dp[i - 1][j] && (j & st) != st) {
				for (int k = 1; k <= 10; ++k) {
					int now = (j << k) | (1 << (k - 1));
					now &= (1 << (x + y + z)) - 1;
					dp[i][now] = (dp[i][now] + dp[i - 1][j]) % mod;
				}
			} 
		}
	}
	for (int i = 0; i < (1 << (x + y + z)); ++ i) {
		if((i & st) != st) ans = ((ans - dp[n][i]) % mod + mod) % mod;
	}
	printf("%d" , ans);
	return 0;
}