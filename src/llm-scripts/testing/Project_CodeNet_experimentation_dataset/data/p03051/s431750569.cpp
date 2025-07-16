#include <bits/stdc++.h>
using namespace std;
const int maxn = 567890, maxm = 1<<20, mod = 1000000007;
int mul(long long a, long long b){
	return a * b % mod;
}
int q0[maxn];
int a[maxn];
vector<int> where[maxm];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) a[i] ^= a[i - 1];
	int cnt0 = 0;
	vector<int> could;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0) cnt0++;
		q0[i] = cnt0;
		could.push_back(a[i]);
	}
	sort(could.begin(), could.end());
	could.erase(unique(could.begin(), could.end()), could.end());
	for(int i = n; i >= 1; i--) where[a[i]].push_back(i);
	int ans = 0;
	for(int i: could){
		if(i == 0){
			int now = a[n] == 0;
			for(int j = where[i].size(); j > 1; j--){
				ans += now;
				if(ans >= mod) ans -= mod;
				now = now + now;
				if(now >= mod) now -= mod;
			}
			ans += a[n] == 0;
			if(ans >= mod) ans -= mod;
			continue;
		}
		int normal = a[n] == i, adapt = mul(normal, q0[n]);
		if(a[n] == i){
			ans += 1;
			if(ans >= mod) ans -= mod;
		} 
		for(int j : where[i]){
			if(j == n) continue;
			int gap = adapt + mod - mul(normal, q0[j]);
			if(gap >= mod) gap -= mod;
			gap += (a[n] == 0);
			if(gap >= mod) gap -= mod;
			ans += gap;
			if(ans >= mod) ans -= mod;
			normal += gap;
			if(normal >= mod) normal -= mod;
			adapt += mul(gap, q0[j]);
			if(adapt >= mod) adapt -= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
