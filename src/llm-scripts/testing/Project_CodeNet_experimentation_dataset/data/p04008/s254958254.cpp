#include<bits/stdc++.h>
#define ll long long
#define inf(x) (ll)(1e##x)
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int fa[101000],n,k,ans,f[101000];
vector<int> e[101000];
void dfs(int x){
	int mx=0;
	for(int v:e[x]) dfs(v),mx=max(mx,f[v]+1);
	if(x==1||fa[x]==1) return;
	if(mx==k-1) ans++,f[x]=-1;
	else f[x]=mx;
}
int main(){
	read(n);read(k);
	for(int i=1;i<=n;i++) read(fa[i]);
	if(fa[1]!=1) fa[1]=1,ans=1;
	for(int i=2;i<=n;i++) e[fa[i]].push_back(i);
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}