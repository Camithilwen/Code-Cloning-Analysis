#include<bits/stdc++.h>
#define rg register
#define il inline
#define int long long
using namespace std;
typedef long long ll;
const int mod=1e9+7,O=200010;
il int gi(){
	rg int o=0,fl=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')fl=-1,ch=getchar();
	while(isdigit(ch))o=o*10+ch-'0',ch=getchar();
	return fl*o;
}
int h,w,a,b,fac[O],inv[O],ans;
il ll C(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
signed main(){
	fac[0]=inv[0]=inv[1]=fac[1]=1;
	for(int i=2;i<O;++i)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<O;++i)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	scanf("%lld%lld%lld%lld",&h,&w,&a,&b);
	for(int i=1;i<=h-a;++i)
		(ans+=C(i+b-2,i-1)*C(h-i+w-b-1,h-i)%mod)%=mod;
	printf("%lld\n",ans);
	return 0;
}
//(1,1)->(i,b)*(i,b)->(n,m)
