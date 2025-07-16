#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int n,m,ty,now,b[N],v[N],vi[N],nex[N],head[N];
void addedges(int x,int y){
	nex[++now]=head[x];
	head[x]=now,v[now]=y;
}
long long c,one,two;
void dfs(int x,int y){
	vi[x]=y;
	for(int i=head[x];i;i=nex[i])
		if(!vi[v[i]])	dfs(v[i],y^1);
		else	if(vi[v[i]]==y)	ty=1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addedges(x,y),++b[x];
		addedges(y,x),++b[y];
	}
	for(int i=1;i<=n;i++)
		if(!vi[i]){
			if(!b[i])	++c;
			else{
				ty=0,dfs(i,2);
				if(ty)	++one;
				else	++two;
			}
		}
	printf("%lld\n",c*n*2-c*c+2*two*(two+one)+one*one);
	return 0;
}
