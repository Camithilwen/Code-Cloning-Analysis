#include<cstdio>
#include<cctype>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define id(a,b) (a*n-n+b)
#define reg register
typedef long long ll;
template<typename T>inline T read(){
    reg T x=0;reg short f=1;reg char c=getchar();
    for(;!isdigit(c);f=c=='-'?-1:1,c=getchar());
    for(;isdigit(c);x=x*10+(c^48),c=getchar());
    return x*f;
}
const int inf=0x3f3f3f3f;
int n,m,h[2005],stk[2005];
bool mp[2005][2005],a[2005][2005];
int main(){
	n=read<int>();m=read<int>();reg int ans=max(n,m);
	for(reg int i=1;i<=n;i++)
		for(reg int j=1;j<=m;j++){
			reg char ch=getchar();
			while(ch!='#'&&ch!='.')ch=getchar();
			mp[i][j]=(ch=='#');
		}
	for(reg int i=1;i<n;i++)
		for(reg int j=1;j<m;j++){
			reg int cnt=(mp[i][j]+mp[i+1][j]+mp[i][j+1]+mp[i+1][j+1])&1;
			if(!cnt)a[i][j]=1;
		}
	for(reg int i=1;i<=n;i++){
		reg int top=0;
		for(reg int j=1;j<m;j++)h[j]=(a[i][j]?h[j]+1:0);
		for(reg int j=1;j<=m;j++){
			while(top&&h[j]<h[stk[top]])
				ans=max(ans,(j-stk[top-1])*(h[stk[top]]+1)),top--;
			stk[++top]=j;
		}
	}
	printf("%d\n",ans);
	return 0;
}