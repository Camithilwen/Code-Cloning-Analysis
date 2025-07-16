#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,cnt;
vector<pii>G[100004];
vector<int>mycol[100004];
vector<pii>g[500004];
int dist[500004];
bool vis[500004];
map<pii,int>mp;
int main(){
	read(n),read(m);
	for (int i=0;i<m;i++){
		int a,b,c;read(a),read(b),read(c);
		G[a].push_back(mkp(b,c));
		G[b].push_back(mkp(a,c));
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<G[i].size();j++)
			if (mp.find(mkp(i,G[i][j].se))==mp.end())
				mp[mkp(i,G[i][j].se)]=++cnt,mycol[i].push_back(cnt);
	for (int i=1;i<=n;i++){
		for (int j=0;j<G[i].size();j++)
			g[mp[mkp(i,G[i][j].se)]].push_back(mkp(mp[mkp(G[i][j].fi,G[i][j].se)],0));
		for (int j=0;j<mycol[i].size();j++) g[mycol[i][j]].push_back(mkp(cnt+i,0)),g[cnt+i].push_back(mkp(mycol[i][j],1)); 
	}
	for (int i=1;i<=cnt+n;i++)dist[i]=1e8;
	deque<int>dq;dist[1+cnt]=0,dq.push_back(1+cnt);
	while (!dq.empty()){
		int x=dq.front();dq.pop_front();
		if (vis[x]) continue;vis[x]=1;
		for (int i=0;i<g[x].size();i++) if (dist[g[x][i].fi]>dist[x]+g[x][i].se){
			dist[g[x][i].fi]=dist[x]+g[x][i].se;
			if (g[x][i].se==0) dq.push_front(g[x][i].fi);
			else dq.push_back(g[x][i].fi);
		}
	}
	if (dist[cnt+n]==1e8) puts("-1");
	else write(dist[cnt+n]);
}