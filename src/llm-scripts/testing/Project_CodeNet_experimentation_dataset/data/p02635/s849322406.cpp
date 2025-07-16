#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
#define P 998244353
const int N=305;
int f[N][N][N],K,ans,n,cn[N];
char s[N];
il void mo(it&p,ct q){p+=q,p=(p>=P?p-P:p);}
int main(){
	scanf("%s%d",s+1,&K),n=strlen(s+1),K=(K<n?K:n);it i,j,k,l,c0;
	for(i=1;i<=n;++i) s[i]=='0'?++c0:++cn[c0];
	f[0][0][0]=1;
	for(i=0;i<=c0;++i)
		for(j=0;j<=K;++j)
			for(k=0;k<=j;++k)
				for(l=-(k<cn[i]?k:cn[i]);l<=K-j;++l)
					mo(f[i+1][j+(l>0?l:0)][k+l],f[i][j][k]);
	for(i=0,++c0;i<=K;++i) ans+=f[c0][i][0],ans=(ans>=P?ans-P:ans);
	printf("%d",ans);
	return 0;
}