#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=4010,M=1000010,P=998244353;
const int inf=0x3f3f3f3f;
const int INF=0xcfcfcfcf;
const double eps=1e-6,pi=asin(1)*2;
inline ll read();
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
inline int ADD(int a,int b) { return a+b>=P?a+b-P:a+b; }
inline int MINUS(int a,int b) { return a-b<0?a-b+P:a-b; }
#define plus(a,b) a=ADD(a,b)
#define minus(a,b) a=MINUS(a,b)
#define mul(a,b) a=(a*(b))%P
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp(x,y) make_pair(x,y)

int K,n;
int C[N][N];
inline void init(int n=4000)
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=ADD(C[i-1][j-1],C[i-1][j]);
	}
}

const int sign[]={1,P-1};

#ifdef FILE
char buf[1<<25],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<25,stdin),p1==p2)?EOF:*p1++
#endif
inline ll read()
{
	ll s=0;
	bool flag=false;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=true;
	for(;'0'<=ch&&ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+(ch^'0');
	if(flag) return -s;
	return s;
}

int main()
{
#ifdef FILE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
#endif
	K=read(),n=read();
	init();
	for(int k=2;k<=2*K;k++)
	{
		int p=min(k/2,K-(k-1)/2);
		int ans=0;
		for(int i=0;i<=p;i++) plus(ans,1ll*sign[i&1]*C[p][i]%P*C[n-2*i+K-1][K-1]%P);
		printf("%d\n",ans);
	}
	return 0;
}