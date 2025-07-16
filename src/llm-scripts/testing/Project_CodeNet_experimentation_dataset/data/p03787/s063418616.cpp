#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
bool w[N],v[N];
int fa[N],sz[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline int find(int x,int &y) {
    if(fa[x]==x) return x;
    fa[x]=find(fa[x],y);
    return v[x]^=y,y=v[x],fa[x];
}
int main() {
    int n,m,A=0,B=0,C=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++) {
	int X=0,Y=0,x=find(gi(),X),y=find(gi(),Y);
	if(x!=y) fa[x]=y,v[x]=X^Y^1,w[y]|=w[x],sz[y]+=sz[x];
	else w[x]|=X^Y^1;
    }
    for(int i=1;i<=n;i++)
	if(fa[i]==i) {
	    if(sz[i]==1) ++A;
	    else if(w[i]) ++B;
	    else ++C;
	}
    cout<<B+C+C+2LL*B*C+2LL*C*(C-1)+2LL*A*n-1LL*A*A+1LL*B*(B-1);
    return 0;
}