#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<int(n); i++)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

vector<int> G[1048576];

int main(){
	int N; cin >> N;
	int A[N];
	rep(i, N) cin >> A[i];
	int rui[N];
	rui[0] = A[0];
	rep(i, N-1){
		rui[i+1] = rui[i] ^ A[i+1];
	}
	int sum[N];
	rep(i, N){
		G[rui[i]].push_back(i);
		if(i == 0){
			if(rui[i] == 0) sum[i] = 1;
			else sum[i] = 0;
		}else{
			if(rui[i] == 0) sum[i] = sum[i-1] + 1;
			else sum[i] = sum[i-1];
		}
	}
	ll ans = 0, s = 1;
	if(rui[N-1] == 0){
		rep(i, sum[N-1] - 1) s = (s * 2) % mod;
		ans = s;
		for(int i=1; i<1048576; i++){
			if(!G[i].size()) continue;
			int p = G[i].size();
			ll dp[p], su = 0;
			dp[p-1] = 1, su = dp[p-1];
			for(int j=p-2; j>=0; j--){
				int nn = sum[G[i][j+1]] - sum[G[i][j]];
				dp[j] = (su * nn % mod + dp[j+1]) % mod;
				su = (su + dp[j]) % mod;
			}
			ans = (ans + su) % mod;
		}
	}else{
		int x = rui[N-1];
		ll dp[G[x].size()], su = 0;
		dp[G[x].size() - 1] = 1, su = 1;
		for(int i=G[x].size() - 2; i>=0; i--){
			if(i == G[x].size() - 2){
				int nn = sum[G[x][i+1]] - sum[G[x][i]];
				dp[i] = nn;
              	su = (su + nn) % mod;
				continue;
			}
			int nn = sum[G[x][i+1]] - sum[G[x][i]];
			dp[i] = (su * nn % mod + dp[i+1]) % mod;
			su = (su + dp[i]) % mod;
		}
		ans = (ans + su) % mod;
	}
	cout << ans << endl;
	return 0;
}
