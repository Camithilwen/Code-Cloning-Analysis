#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const LL mod = 1e9+7;

int main(){
	int N; cin >> N;
	vector<int> A(N);
	int x = 0, y = 0;
	vector<vector<vector<int>>> name(1<<20,vector<vector<int>>(2,vector<int>(2,0)));
	vector<vector<LL>> dp(1<<20,vector<LL>(3,0));
	repp(i,0,N){
		cin >> A[i];
		x ^= A[i];
		if(x == 0){
			++y;
		} else {
			if(dp[x][2] < y){
				(dp[x][0] += dp[x][1]*(y-dp[x][2])) %= mod;
				dp[x][2] = y;
			}
			(dp[x][1] += dp[x][0]+1) %= mod;
		}
	}
	if(x == 0){
		LL ans = 1;
		repp(i,1,y) ans = ans*2%mod;
		repp(k,1,1<<20){
			(ans += dp[k][1]) %= mod;
		}
		cout << ans << endl;
	} else {
		cout << dp[x][0]+1 << endl;
	}
	return 0;
}
