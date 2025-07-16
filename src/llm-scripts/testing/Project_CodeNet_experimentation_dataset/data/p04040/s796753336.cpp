#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 
int h,w,a,b,fac[200006],ans=0,inv_fac[200006];
int binpow(int x,int y){
	if(y==0) return 1;
	else{
		long long tmp=binpow(x,y/2);
		if(y%2==1) return ((tmp*tmp)%mod*x)%mod;
		else return (tmp*tmp)%mod;
	}
}
 
int C(int k,int n) {
	return fac[n]*inv_fac[k]%mod*inv_fac[n-k]%mod;
}
 
int path(int x1,int y1,int x2,int y2) {
	if(x1>x2||y1>y2) return 1;
	return  C(x2-x1,x2-x1+y2-y1)%mod;
}
 
signed main() {
	cin>>h>>w>>a>>b;
	fac[0]=1;
	inv_fac[0]=1;
	for(int i=1;i<=200005;++i) 
	{
		fac[i]=((i % mod)*fac[i-1])%mod;
		inv_fac[i]=binpow(fac[i],mod-2)%mod;
	}
	for(int i=1;i<=h-a;++i) {
		ans+=((path(1,1,i,b)%mod)*(path(i,b+1,h,w)%mod))%mod;
	}
	cout<<ans%mod;
}