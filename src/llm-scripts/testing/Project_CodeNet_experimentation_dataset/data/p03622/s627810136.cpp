#include<bits/stdc++.h>
#define LL long long
#define uLL unsigned long long
#define db double

using namespace std;
const int N=5e5+10,mod=998244353;
int rd()
{
	int x=0,w=1;char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*w;
};
void ad(int &x,int y){x+=y,x-=x>=mod?mod:0;}
int fpow(int a,int b){int an=1;while(b){if(b&1) an=1ll*an*a%mod;a=1ll*a*a%mod,b>>=1;} return an;}
int ginv(int a){return fpow(a,mod-2);}
int n,m,fac[N<<1],iac[N<<1];
int C(int a,int b){return b<0||a<b?0:1ll*fac[a]*iac[b]%mod*iac[a-b]%mod;}

int main()
{
	fac[0]=1;
	for(int i=1;i<=1000000;++i) fac[i]=1ll*fac[i-1]*i%mod;
	iac[1000000]=ginv(fac[1000000]);
	for(int i=1000000;i;--i) iac[i-1]=1ll*iac[i]*i%mod;
	n=rd(),m=rd();
	if(n<m) swap(n,m);
	int ans=0;
	for(int i=1;i<=n;++i) ad(ans,1ll*C(i+i,i)*C(n+m-i-i,n-i)%mod);
	ans=1ll*ans*ginv(C(n+m,n))%mod*ginv(2)%mod;
	ad(ans,n);
	printf("%d\n",ans);
	return 0; 
}
