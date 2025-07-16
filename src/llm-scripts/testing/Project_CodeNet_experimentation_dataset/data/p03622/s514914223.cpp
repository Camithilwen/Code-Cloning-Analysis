#include <cstdio>
typedef long long LL;
const int N=1000005,mo=998244353;
LL fac[N],inv[N];
LL ksm(LL x,int y){
	LL i=1;
	for (;y;y>>=1,x=x*x%mo)
		if (y&1) i=i*x%mo;
	return i;
}
void Pre(int n){
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mo;
	inv[n]=ksm(fac[n],mo-2);
	for (int i=n;i>=1;i--) inv[i-1]=inv[i]*i%mo;
}
LL C(int n,int m){
	return n<m||m<0?0:fac[n]*inv[m]%mo*inv[n-m]%mo;
}
LL INV(int n){
	return inv[n]*fac[n-1]%mo;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	Pre(n+m);
	int ans=0,sum=0,s=C(n+m,n);
	for (int i=1;i<=n+m;i++){
		if (i&1)
			s=(s+C(i-2,i/2)*C(n+m-i+1,n-i/2))%mo;
		else
			s=(s-C(i-2,i/2-1)*C(n+m-i,n-i/2)*2)%mo;
		sum=(sum+s)%mo;
		ans=(ans+sum*INV(i))%mo;
	}
	ans=ans*ksm(C(n+m,n),mo-2)%mo;
	printf("%d\n",(ans+mo)%mo);
}