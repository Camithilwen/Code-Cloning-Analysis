
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll oo = 1e18;
const int MOD = 1000000007;
const int N = 300010;
#define x first
#define y second
#define pb push_back
#define mp make_pair

int n , m , dp[1 << 16][16], comp[1 << 16], cost[16][1 << 16], vis[1 << 16],val[1<<16], vsId;
struct edge {
	int s , t , c;
};
edge E[16 * 16];
int solve(int msk , int p){
	if(p == n-1)return !msk?0:-1e9;
	int &ret = dp[msk][p];
	if(ret != -1)return ret;
	ret = -1e9;
	for (int i = 0; i < n; ++i){
		if((msk&(1<<i))>0 && cost[i][1<<p]){
			ret = max(ret,cost[i][1<<p]+solve(msk^(1<<i),i));
		}
	}
	return ret;
}
ll all = 0;
vector<int> nodes;
int calc(int msk){
	if(!msk)return 0;
	if(vis[msk]==vsId)return val[msk];
	vis[msk] = vsId;
	int &ret = val[msk];
	ret = -1e9;
	for(int sub = msk ; sub > 0 ; sub=(sub-1)&msk){
		for(int u = 0 ; u < nodes.size() ; ++u){
			int j = nodes[u];
			ret = max(ret,cost[j][sub]+comp[sub]+calc(msk^sub));
		}
	}
	return ret;
}

int main() {
	memset(dp,-1,sizeof dp);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &E[i].s, &E[i].t, &E[i].c);
		E[i].s--, E[i].t--;
		all += E[i].c;
	}
	for (int i = 0; i < n; ++i) {
		for (int msk = 0; msk < (1 << n); ++msk) {
			for (int j = 0 ; j < m ; ++j) {
				if (E[j].t == i)
					swap(E[j].s, E[j].t);
				if (E[j].s == i && (msk & (1 << E[j].t)) > 0) {
					cost[i][msk] += E[j].c;
				}
			}
		}
	}
	for (int msk = 0; msk < (1 << n); ++msk) {
		for (int j = 0 ; j < m ; ++j) {
			if((msk & (1 << E[j].s)) > 0 && (msk & (1 << E[j].t)) > 0){
				comp[msk] += E[j].c;
			}
		}
	}
	ll ans = oo;
	for (int msk = 0 ; msk < (1<< n); ++msk){
		if((msk&(1<<0))==0||(msk&(1<<(n-1)))==0)continue;
		if(solve(msk^(1<<0),0) < 0)continue;
		nodes.clear();
		vsId++;
		for(int i = 0 ; i < n ; ++i)
			if((msk&(1<<i))>0)nodes.pb(i);
		ans = min(ans,all-solve(msk^(1<<0),0)-calc(~msk&((1<<n)-1)));
	}
	printf("%lld\n",ans );
	return 0;
}
