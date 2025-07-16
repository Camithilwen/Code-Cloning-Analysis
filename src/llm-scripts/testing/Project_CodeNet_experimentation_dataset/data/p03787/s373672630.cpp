#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50;
int gi(){
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}
int vis[N],d[N],head[N],nn[N][2],cnt=1,flag;
ll ans;
#define link(u,v) (nn[++cnt][1]=v,nn[cnt][0]=head[u],head[u]=cnt)
void dfs(int x,int op){
    if (vis[x]){
	if (op!=d[x]) flag=1;
	return;
    }
    vis[x]=1,d[x]=op;
    for (int i=head[x]; i; i=nn[i][0])
	dfs(nn[i][1],op^1);
    return;
}
int main(){
    int n=gi(),m=gi(),u,v;
    for (int i=1; i<=m; ++i)
	u=gi(),v=gi(),link(u,v),link(v,u);
    int a=0,b=0,c=0;
    for (int i=1;  i<=n; ++i)
	if (!head[i]) ++a;
    for (int i=1; i<=n; ++i)
	if (head[i]&&!vis[i]){
	    flag=0,dfs(i,0);
	    if (flag) ++b;
	    else ++c;
	}
    cout<<2ll*a*n-1ll*a*a+1ll*b*b+2ll*c*(b+c);
    return 0;
}
