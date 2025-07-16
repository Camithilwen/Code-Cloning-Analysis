#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void read(int &x) {
	char ch; bool ok;
	for(ok=0,ch=getchar(); !isdigit(ch); ch=getchar()) if(ch=='-') ok=1;
	for(x=0; isdigit(ch); x=x*10+ch-'0',ch=getchar()); if(ok) x=-x;
}
#define rg register
const int maxn=1e5+10;bool vis[maxn];
int n,k,dep[maxn],ans,f[maxn],cnt,pre[maxn*2],nxt[maxn*2],h[maxn];
void add(int x,int y){
	pre[++cnt]=y,nxt[cnt]=h[x],h[x]=cnt;
}
void dfs(int x){
	vis[x]=1;
	for(rg int i=h[x];i;i=nxt[i])
		if(!vis[pre[i]])dfs(pre[i]),dep[x]=max(dep[pre[i]]+1,dep[x]);
	if(dep[x]>=k-1&&f[x]!=1)dep[x]=-1,ans++;
}
int main()
{
	read(n),read(k);scanf("%d",&f[1]);
	for(rg int i=2;i<=n;i++)read(f[i]),add(f[i],i);
	if(f[1]!=1)ans++,f[1]=1;dfs(1);
	printf("%d\n",ans);
}