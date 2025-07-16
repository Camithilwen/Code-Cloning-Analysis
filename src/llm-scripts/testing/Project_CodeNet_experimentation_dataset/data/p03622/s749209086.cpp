#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const int mo=998244353;
int fac[N],inv[N],n,m,ans;
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int main(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo,
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n&&i<=m;i++)
		ans=(ans+1ll*C(i*2,i)*C(n+m-i*2,n-i))%mo;
	ans=1ll*ans*inv[n+m]%mo*fac[n]%mo*fac[m]%mo*(mo+1)/2%mo;
	printf("%d",(ans+max(n,m))%mo);
} 