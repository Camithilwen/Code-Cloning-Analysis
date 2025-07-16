#include<cstdio>
#include<cctype>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5,M=2e5,P=N+2*M,inf=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,m,tot;
vector<pii>e[P+1];
int dis[P+1];
int read()
{
	int ret=0;
	char c=getchar();
	while(!isdigit(c)) {
		c=getchar();
	}
	while(isdigit(c)) {
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
int get_number(int p,int c)
{
	static unordered_map<long long,int>mp;
	long long has=(long long)p<<32|c;
	if(!mp[has]) {
		mp[has]=++tot;
	}
	return mp[has];
}
void dijkstra()
{
	static bool vis[P+1];
	static priority_queue<pii,vector<pii>,greater<pii>>que;
	fill(dis+1,dis+tot+1,inf);
	que.push(pii{dis[1]=0,1});
	while(!que.empty()) {
		int u=que.top().second;
		que.pop();
		if(vis[u]) {
			continue;
		}
		vis[u]=true;
		for(pii e:e[u]) {
			int v=e.first;
			if(dis[u]+e.second<dis[v]) {
				que.push(pii{dis[v]=dis[u]+e.second,v});
			}
		}
	}
	return;
}
int main()
{
	n=read(),m=read();
	tot=n;
	for(int i=1,u,v,c;i<=m;++i) {
		u=read(),v=read(),c=read();
		int uc=get_number(u,c),vc=get_number(v,c);
		e[u].push_back(pii{uc,1}),e[uc].push_back(pii{u,1});
		e[v].push_back(pii{vc,1}),e[vc].push_back(pii{v,1});
		e[uc].push_back(pii{vc,0}),e[vc].push_back(pii{uc,0});
	}
	dijkstra();
	printf("%d\n",dis[n]==inf?-1:dis[n]/2);
	return 0;
}
