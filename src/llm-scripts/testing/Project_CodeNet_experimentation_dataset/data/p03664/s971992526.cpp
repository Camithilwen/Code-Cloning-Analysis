#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 15;

struct edg{
	int s, e, x;
};

vector<edg> v;
int cyc[1 << MAXN];
int dp[1 << MAXN][MAXN];
int adj[MAXN][MAXN];
int n, m;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXN; j++){
			adj[i][j] = -1e9;
		}
	}
	int ans = 0;
	for(int i=0; i<m; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		adj[s-1][e-1] = x;
		adj[e-1][s-1] = x;
		v.push_back({s-1, e-1, x});
	}
	for(int i=0; i<(1<<n); i++){
		for(auto &j : v){
			if((i >> j.s) % 2 == 1 & (i >> j.e) % 2 == 1){
				cyc[i] += j.x;
			}
		}
	}
	for(int i=0; i<(1<<n); i++){
		for(int j=0; j<n; j++){
			dp[i][j] = -1e9;
			if((i >> j) % 2 == 0){
				continue;
			}
			if(j == 0){
				dp[i][j] = cyc[i];
			}
			for(int k=i; k; k=(k-1)&i){
				if((k >> j) % 2 == 0) continue;
				for(int l=0; l<n; l++){
					dp[i][j] = max(dp[i][j], dp[i^k][l] + adj[l][j] + cyc[k]);
				}
			}
		}
	}
	int ret = dp[(1<<n)-1][n-1];
	for(auto &i : v) ret -= i.x;
	cout << -ret << endl;
}
