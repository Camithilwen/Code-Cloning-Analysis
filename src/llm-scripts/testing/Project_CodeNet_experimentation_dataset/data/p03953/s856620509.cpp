#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
const int MAXN=100001;
int m,k,ans,n,x[MAXN],d[MAXN],a[MAXN],fa[MAXN][61],p[MAXN];
signed main(){
//	freopen("2.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++) x[i]=read(),d[i]=i,p[i]=x[i]-x[i-1];
	m=read(),k=read();
	for(int i=1;i<=m;i++) a[i]=read(),swap(d[a[i]],d[a[i]+1]);
	for(int i=1;i<=n;i++) fa[i][0]=d[i];
	for(int j=1;j<=60;j++)
		for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int i=1;i<=n;i++){
		int res=i;
		int K=k;
		for(int j=60;j>=0;j--) if(K-(1ll<<j)>=0) K-=(1ll<<j),res=fa[res][j];
		ans+=p[res];
		printf("%lld.0\n",ans);
	}return 0;
}/*
3
1 -1 1
2 2
2 2
*/