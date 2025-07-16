#include<cstdio>
using namespace std;
#define LL long long
#define mod 998244353
const int NN=1000000+117;
LL fact[NN]={};
LL rev[NN]={};
LL comp(int m,int n){
	return fact[n]*rev[m]%mod*rev[n-m]%mod;
}
LL ksm(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1){
			(ret*=a)%=mod;
		}
		(a*=a)%=mod;
		b>>=1;
	}
	return ret;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int top=n+m;
	fact[0]=1;
	for(int i=1;i<=top;++i)
		fact[i]=fact[i-1]*i%mod;
	rev[top]=ksm(fact[top],mod-2);
	for(int i=top;i>=1;--i)
		rev[i-1]=rev[i]*i%mod;
	if(n<m)m^=n^=m^=n;
	LL ans=0;
	for(int i=1;i<=m;++i){
		ans+=comp(i,2*i)*comp(m-i,n+m-2*i)%mod;
		ans%=mod;
	}
	ans=ans*rev[2]%mod*rev[m+n]%mod*fact[n]%mod*fact[m]%mod;
	ans+=n;
	ans%=mod;
	printf("%lld\n",ans);
}