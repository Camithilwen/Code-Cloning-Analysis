#include<bits/stdc++.h>
using namespace std;
struct edge{
	int y,nxt,v;
}e[2000010];
set<int>c[2000010];
int n,m,head[2000010],dis[2000010],vis[2000010],tot;
void add(int x,int y,int v){
	e[++tot]=edge{y,head[x],v};
	head[x]=tot;
}
void dijkstra(){
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[1]=0; q.push(make_pair(0,1));
	while(q.size()){
		int x=q.top().second; q.pop();
		if(vis[x]) continue; vis[x]=1;
//		cout<<x<<':'<<dis[x]<<endl;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].y,v=c[x].count(e[i].v)?0:1;
//			cout<<"y = "<<y<<endl;
			if(dis[x]+v<dis[y]){
				dis[y]=dis[x]+v;
				q.push(make_pair(-dis[y],y));
				c[y].clear(); c[y].insert(e[i].v);
			}
			else if(dis[x]+v==dis[y]) c[y].insert(e[i].v);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dijkstra();
//	cout<<0x3f3f3f3f3f<<endl;
	if(dis[n]==0x3f3f3f3f) printf("-1");
	else printf("%d",dis[n]);
	return 0;
}