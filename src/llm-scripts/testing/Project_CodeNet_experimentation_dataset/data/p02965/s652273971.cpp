#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
const int mod=998244353;
const int MAXN=3000005;
int pre[MAXN],inv[MAXN];
int C(int n,int m)
{
	if(n<m)return 0;
	return 1LL*pre[n]*inv[m]%mod*inv[n-m]%mod;
}
int n,m;
void ad(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void dl(int &x,int y){x-=y;if(x<0)x+=mod;}
int pow_mod(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)ret=1LL*ret*a%mod;
		a=1LL*a*a%mod;b>>=1;
	}
	return ret;
}
int main()
{
	pre[0]=1;for(int i=1;i<MAXN;i++)pre[i]=1LL*pre[i-1]*i%mod;
	inv[MAXN-1]=pow_mod(pre[MAXN-1],mod-2);
	for(int i=MAXN-2;i>=0;i--)inv[i]=1LL*inv[i+1]*(i+1)%mod;
	n=read();m=read();
	int ans=0;
	for(int i=0;i<=m;i++)
		if(!((3*m-i)&1))
			ad(ans,1LL*C(n,i)*C(((3*m-i)>>1)+n-1,n-1)%mod);
//	dl(ans,1LL*n*C(m-2+n-1,n-1)%mod);
	dl(ans,1LL*n*C(m-1+n-1,n-1)%mod);
	pr2(ans);
	return 0;
}


