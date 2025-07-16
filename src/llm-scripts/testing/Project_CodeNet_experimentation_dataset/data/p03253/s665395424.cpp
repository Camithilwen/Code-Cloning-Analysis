#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;

const long long MAX = 1000100;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i = 2;i < MAX;i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
long long COM(int n, int k){
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
	COMinit();
	int n,m;
	cin >> n >> m;

	map<int,int> mp;
	for(int i = 2;i * i <= m;i++){
		while(m % i == 0){
			mp[i]++;
			m /= i;
		}
	}

	if(m != 1)mp[m]++;

	ll ans = 1;

	for(auto p:mp){
		ll com = COM(p.second+n-1,p.second);
		ans *= com;
		ans %= MOD;
	}

	cout << ans << endl;
}
