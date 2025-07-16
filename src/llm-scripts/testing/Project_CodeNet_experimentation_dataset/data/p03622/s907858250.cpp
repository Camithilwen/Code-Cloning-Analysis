#include<bits/stdc++.h>
const int N=1e6+9,mo=998244353;
int f[N/2],f2[N/2],G[N/2],mi[N],vf[N],inv[N],fac[N],i,n,m,z,ans;
inline int C(int x,int y){return x<y?0:1ll*vf[y]*vf[x-y]%mo*fac[x]%mo;}
int main(){
	*f=*f2=1;
	for(i=*mi=*vf=*fac=1;i<N;++i)mi[i]=4ll*mi[i-1]%mo,inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		fac[i]=1ll*i*fac[i-1]%mo,vf[i]=1ll*vf[i-1]*inv[i]%mo;
	scanf("%d%d",&n,&m);if(n>m)std::swap(n,m);
	for(i=0;i<n;++i)f[i+1]=1ll*inv[i+1]*(4*i+2)%mo*f[i]%mo;
	for(i=0;i<n;++i)f2[i+1]=1ll*inv[2*i+2]%mo*(8*i+12)%mo*f2[i]%mo;
	for(i=1;i<=n;++i)G[i]=(1ll*inv[2]*(mi[i]+mo-f[i])+f2[i-1]*2)%mo;
	if(n==m)ans=G[n];else for(i=0,z=m-n;i<=n;++i)ans=(ans+1ll*(G[n-i]+
		1ll*(i+z)*C(n*2-i*2,n-i))%mo*(C(z-1+i*2,i)+mo-C(z-1+i*2,i+z)))%mo;
	ans=1ll*fac[n]*fac[m]%mo*vf[n+m]%mo*ans%mo;
	printf("%d\n",ans);
	return 0;
}