#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0; char c=getchar(); int flag=1;
	while(!isdigit(c)) { if(c=='-') flag=-1; c=getchar(); }
	while(isdigit(c)) { x=((x+(x<<2))<<1)+(c^48); c=getchar(); }
	return x*flag;
}

const int N=1e5+50;

int n,k;

struct Edge{
    int to,next;
}edge[N<<1];
int head[N];
int tmp=0;
void add(int x,int y){
    ++tmp;
    edge[tmp].to=y; edge[tmp].next=head[x];
    head[x]=tmp;
}

int a[N];
int ans;

int dfs(int nod,int dep){
    int ret=dep;
    for(int i=head[nod];i!=-1;i=edge[i].next){
	    ret=max(ret,dfs(edge[i].to,dep+1));
	}
	if(a[nod]!=1&&ret-dep==k-1) { ++ans; return 0; }
	return ret; 
}

signed main(){
	memset(head,-1,sizeof(head));
	
    n=read(),k=read();
    for(int i=1;i<=n;i++) a[i]=read();
    
    if(a[1]!=1) ans=1,a[1]=1;
    
    for(int i=2;i<=n;i++) add(a[i],i);
    
    dfs(1,0); 
    
    printf("%d\n",ans);
    return 0;
}
