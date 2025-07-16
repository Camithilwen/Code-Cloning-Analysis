#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
const ll MOD = (ll)1e9+7;
const ll INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){
	return modpow(x, MOD-2);
}

int main(){
	int n;
	cin >> n;
	vector<vector<ll>> citys(n, vector<ll>(2));
	foreach(i, citys){ 
		foreach(j, i)cin>>j;
	}


	vector<vector<pll>> roads(n);

	rep(i, 2){
		vector<pll> line;
		rep(j, n){
			line.emplace_back(citys[j][i], j);
		}
		sort(all(line));
		rep(j, n-1){
			pll a = line[j];
			pll b = line[j+1];
			roads[a.second].emplace_back(abs(a.first-b.first), b.second);
			roads[b.second].emplace_back(abs(a.first-b.first), a.second);
		}
	}

	vector<bool> used(n, false);
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	ll ans = 0;
	pq.emplace(0, 0);
	while(pq.size()){
		pll d = pq.top();
		pq.pop();
		if(used[d.second])continue;
		used[d.second] = true;
		ans += d.first;
		foreach(i, roads[d.second]){
			if(used[i.second])continue;
			pq.push(i);
		}
	}

	cout << ans << endl;

	return 0;
}
