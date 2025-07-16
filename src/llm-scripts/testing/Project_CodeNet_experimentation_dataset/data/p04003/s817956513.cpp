#include<bits/stdc++.h>
using namespace std;
int head[600100],cnt,n,m,lim,dis[600100];
struct Node{
	int to,next,val;
}edge[4001000];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
}
map<pair<int,int>,int>mp;
priority_queue<pair<int,int> >q;
bool vis[600100];
int dijkstra(){
	dis[1]=0,q.push(make_pair(0,1));
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;vis[x]=true;
		for(int i=head[x];i!=-1;i=edge[i].next)if(dis[edge[i].to]>dis[x]+edge[i].val)dis[edge[i].to]=dis[x]+edge[i].val,q.push(make_pair(-dis[edge[i].to],edge[i].to));
	}
	return dis[n]==0x3f3f3f3f?-1:dis[n];
}
int hs(int x,int c){
	if(mp.find(make_pair(x,c))!=mp.end())return mp[make_pair(x,c)];
	lim++;
//	printf("(%d,%d)->%d\n",x,c,lim);
	ae(x,lim,1);
	ae(lim,x,0);
	return mp[make_pair(x,c)]=lim;
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head)),memset(dis,0x3f3f3f3f,sizeof(dis)),lim=n;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ae(hs(u,w),hs(v,w),0),ae(hs(v,w),hs(u,w),0);
	}
	printf("%d\n",dijkstra());
	return 0;
}