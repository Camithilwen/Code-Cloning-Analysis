#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 501, MAX_M = 2e5+10;
int N, M, Q;
int L[MAX_M], R[MAX_M];
int p[MAX_M], q[MAX_M];
ll ans[MAX_N][MAX_N];

void solve()
{
	for(int i=0;i<M;++i){
		for(int le=1;le<=L[i];++le)ans[le][R[i]]++;
	}
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
        ans[i][j] += ans[i][j-1];
	}
	for(int i=0;i<Q;++i){
		cout << ans[p[i]][q[i]] << '\n';
	}
}

int main()
{
	cin >> N >> M >> Q;
	for(int i=0;i<M;++i) cin >> L[i] >> R[i];
	for(int i=0;i<Q;++i) cin >> p[i] >> q[i];
	solve();
	return 0;
}