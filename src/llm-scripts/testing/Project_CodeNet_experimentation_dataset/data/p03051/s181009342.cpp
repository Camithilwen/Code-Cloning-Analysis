#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
llint a[500005], s[500005];
llint z[500005];
vector<llint> vec[500005];
llint sum[500005];
llint dp[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) s[i] = s[i-1] ^ a[i];
	
	bool flag = false;
	for(int i = 1; i <= n; i++){
		if(s[i] == 0) flag = true;
	}
	if(!flag){
		cout << 1 << endl;
		return 0;
	}
	
	vector<llint> comp;
	for(int i = 1; i <= n; i++) comp.push_back(s[i]);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n; i++) s[i] = lower_bound(comp.begin(), comp.end(), s[i]) - comp.begin();
	
	llint S = s[n];
	
	for(int i = 1; i <= n; i++) vec[s[i]].push_back(i);
	for(int i = 1; i <= n; i++){
		z[i] = z[i-1];
		if(s[i] == 0) z[i]++, z[i] %= mod;
	}
	
	//for(int i = 1; i <= n; i++) cout << s[i] << " "; cout << endl;
	//cout << S << endl;
	
	llint ans = 0;
	for(int i = 1; i < 500005; i++){
		llint N = vec[i].size();
				if(N == 0) continue;
		llint have = 0, sum = 0;
		dp[0] = 1, have++;
		for(int j = 1; j < N; j++){
			sum += have * (z[vec[i][j]] - z[vec[i][j-1]] + mod) % mod, sum %= mod;
			dp[j] = sum+1;
			have += dp[j], have %= mod;
		}
		if(S == 0){
			for(int j = 0; j < N; j++) ans += dp[j], ans %= mod;
		}
		else{
			if(i == S) ans += dp[N-1], ans %= mod;
		}
		//for(int j = 0; j < N; j++) cout << dp[j] << " "; cout << endl;
	}
	//cout << ans << endl;
	if(S == 0){
		llint tmp = 1;
		for(int i = 1; i < vec[0].size(); i++) tmp *= 2, tmp %= mod;
		ans += tmp, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}