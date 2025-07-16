#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod=998244353;
int n,m,f[1000005],inv[1000005];
long long C(int n,int m){
	return 1LL*f[n]*inv[m]%mod*inv[n-m]%mod;
}
long long quick_pow(long long a,int b){
	long long ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1) ans=ans*a%mod;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	if(n<m) swap(n,m);
	f[0]=f[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=1000002;i++) f[i]=1LL*f[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=1000002;i++) inv[i]=1LL*inv[i]*inv[i-1]%mod;
	long long ans=0;
	for(int i=1;i<=m;i++){
		ans=(ans+C(i+i,i)*C(n-i+m-i,n-i))%mod;
	}
	ans=(ans*quick_pow(2*C(n+m,n),mod-2)+n)%mod;
	printf("%lld",ans);
	return 0;
}