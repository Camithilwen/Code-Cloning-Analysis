#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define N 100002
using namespace std;
struct node{
	int u,v,w;
}e[200002];
vector<int> id[N];
int head[2000002],ver[2000002],nxt[2000002],edge[2000002],l;
int n,m,i,j,cnt[N],now[N],dis[2000002],num;
bool in[2000002];
int read()
{
	char c=getchar();
	int w=0;
	while(c<'0'||c>'9') c=getchar();
	while(c<='9'&&c>='0'){
		w=w*10+c-'0';
		c=getchar();
	}
	return w;
}
int my_comp(const node &x,const node &y)
{
	return x.w<y.w;
}
void insert(int x,int y,double z)
{
	l++;
	ver[l]=y;
	edge[l]=z;
	nxt[l]=head[x];
	head[x]=l;
}
void SPFA(int s)
{
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	q.push(s);
	dis[s]=0;in[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			if(dis[y]>dis[x]+edge[i]){
				dis[y]=dis[x]+edge[i];
				if(!in[y]){
					in[y]=1;
					q.push(y);
				}
			}
		}
		in[x]=0;
	}
}
int main()
{
	n=read(),m=read();
	for(i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1,my_comp);
	for(i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(now[u]!=w) cnt[u]++,now[u]=w,id[u].push_back(++num);
		if(now[v]!=w) cnt[v]++,now[v]=w,id[v].push_back(++num);
		insert(id[u][cnt[u]-1],id[v][cnt[v]-1],0);
		insert(id[v][cnt[v]-1],id[u][cnt[u]-1],0);
	}
	for(i=1;i<=n;i++){
		for(j=0;j<cnt[i];j++){
			insert(num+i,id[i][j],1);
			insert(id[i][j],num+i,1);
		}
	}
	SPFA(num+1);
	if(dis[num+n]==dis[0]) cout<<"-1"<<endl;
	else cout<<dis[num+n]/2<<endl;
	return 0;
}
