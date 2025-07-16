#include<bits/stdc++.h>
using namespace std;

const int N=1001000;
int fa[N],n,m,q[N],d[N],a[N],bl[N];
vector<int>g[N];
vector<pair<int,int> >vec[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(int x,int y){g[x].push_back(y);g[y].push_back(x);}

int bfs(int S,int T){
	for(int i=1;i<=n;++i)d[i]=-2;
	d[S]=0;int t=-1,w=0;q[0]=S;
	for(;t<w;){
		int x=q[++t];
		for(int i:g[x])if(d[i]==-2)d[i]=d[x]+1,q[++w]=i;
	}
	return d[T];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;int S=1,T=n,mx=0;
	for(int i=1;i<=m;++i){
		int x,y,z;cin>>x>>y>>z;mx=max(mx,z);
		vec[z].emplace_back(x,y);
	}
	for(int i=1;i<=mx;++i)if(!vec[i].empty()){
		int cnt=0;
		for(auto j:vec[i])a[++cnt]=j.first,a[++cnt]=j.second;
		sort(a+1,a+cnt+1);cnt=unique(a+1,a+cnt+1)-a-1;
		for(int j=1;j<=cnt;++j)fa[a[j]]=a[j];
		for(auto j:vec[i])fa[find(j.first)]=find(j.second);
		for(int j=1;j<=cnt;++j)if(fa[a[j]]==a[j])bl[a[j]]=++n;
		for(int j=1;j<=cnt;++j)add(a[j],bl[find(a[j])]);
	}
	cout<<(bfs(S,T)/2)<<'\n';
	return 0;
}
