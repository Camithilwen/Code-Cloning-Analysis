#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define se second
#define fi first
const int N=2000005;
int n,m,tot,l,x,y,z,f[N],dis[N],to[N],ne[N],fi[N],zz[N],g[N];
vector<pair<int ,int> > G[N];
vector<int> v;
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
int find(int x){
	if (x==f[x])return x;
	return f[x]=find(f[x]);
}
void up(int x){
	if (x==1)return;
	if (dis[f[x]]<dis[f[x/2]]){
		swap(f[x],f[x/2]);
		swap(g[f[x]],g[f[x/2]]);
		up(x/2);
	}
}
void down(int x){
	int i=x;
	if (x*2<=l&&dis[f[x*2]]<dis[f[x]])i=x*2;
	if (x*2<l&&dis[f[x*2+1]]<dis[f[i]])i=x*2+1;
	if (i!=x){
		swap(f[x],f[i]);
		swap(g[f[x]],g[f[i]]);
		down(i);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	while (m--){
		scanf("%d%d%d",&x,&y,&z);
		G[z].push_back(mp(x,y));
	}
	for (int i=1;i<=n;i++)f[i]=i;
	int cnt=n;
	for (int i=1;i<=1000000;i++){
		v.clear();
		for (int j=0;j<G[i].size();j++)f[find(G[i][j].fi)]=find(G[i][j].se);
		for (int j=0;j<G[i].size();j++)v.push_back(G[i][j].fi),v.push_back(G[i][j].se);
		for (int j=0;j<v.size();j++)
			if (find(v[j])==v[j])to[v[j]]=++cnt;
		for (int j=0;j<v.size();j++)jb(to[find(v[j])],v[j]),jb(v[j],to[find(v[j])]);
		for (int j=0;j<v.size();j++)f[v[j]]=v[j];
	}
	dis[1]=0;
	for (int i=2;i<=cnt;i++)dis[i]=1e9;
	for (int i=1;i<=cnt;i++)f[i]=g[i]=i;
	l=cnt;
	for (int i=cnt;i;i--)down(i);
	for (int i=1;i<=cnt;i++){
		int k=f[1];
		f[1]=f[l--];
		g[f[1]]=1;
		down(1);
		for (int j=fi[k];j;j=ne[j])
			if (dis[zz[j]]>dis[k]+1){
				dis[zz[j]]=dis[k]+1;
				up(g[zz[j]]);
			}
	}
	if (dis[n]==1e9)puts("-1");
	else printf("%d\n",dis[n]/2);
	return 0;
}