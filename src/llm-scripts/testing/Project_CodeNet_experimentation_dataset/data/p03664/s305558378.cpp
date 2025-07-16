#include <bits/stdc++.h>
 
using std::max;
 
const int N=15,Inf=1e9+10;
 
int n,m,map[N][N],f[N][1<<N],M[N][1<<N],sum[1<<N];
 
void Init() {
	scanf("%d%d",&n,&m);
	int a,b,c;
	for (int i=1;i<=m;++i) {
		scanf("%d%d%d",&a,&b,&c);
		a--; b--; 
		map[a][b]=map[b][a]=c;
	}
}
 
int summ;
bool vis[N];
void Dfs(int x,int s) {
	if (vis[x]) return ;
	vis[x]=1;
	for (int i=0;i<n;++i) if ((1<<i)&s && map[x][i]) {
		summ+=map[x][i];
		Dfs(i,s);
	}
}
 
void Solve() {
	int Max=1<<n;
	for (int s=0;s<Max;++s) {
		summ=0;
		for (int i=0;i<n;++i) vis[i]=0;
		for (int i=0;i<n;++i) if ((1<<i)&s) Dfs(i,s);
		sum[s]=summ>>1;
	}
	
	summ=0;
	for (int i=0;i<n;++i)
		for (int j=i;j<n;++j) summ+=map[i][j];
	for (int i=0;i<n;++i)
		for (int s=0;s<Max;++s) f[i][s]=-Inf,M[i][s]=-Inf;
	M[0][1]=0;
	for (int s=0;s<Max;++s) if (s&1) {
		f[0][s]=sum[s];
		for (int t=0;t<n;++t) 
			if (map[t][0]) M[t][s]=max(M[t][s],f[0][s]+map[t][0]);
	}
	for (int s=0;s<Max;++s) {
		for (int i=0;i<n;++i) if ((1<<i)&s) {
			for (int p=s;p;p=(p-1)&s) if (!((1<<i)&p)) {
				f[i][s]=max(f[i][s],M[i][p]+sum[s^p]);
			}
			for (int t=0;t<n;++t) if (map[t][i]) M[t][s]=max(M[t][s],f[i][s]+map[t][i]);
		}
	}
	
	printf("%d\n",summ-f[n-1][Max-1]);
}
 
int main() {
	Init();
	Solve();
	return 0;
}