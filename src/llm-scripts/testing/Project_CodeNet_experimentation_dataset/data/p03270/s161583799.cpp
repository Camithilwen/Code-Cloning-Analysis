#include<bits/stdc++.h>
#define reg register
#define F(i,j,k) for(reg int i=j;i<=k;++i)
#define dF(i,j,k) for(reg int i=j;i>=k;--i)
using namespace std;
typedef long long ll;
int n,k;
const int mod=998244353;
const int MN=2005;
int C[MN<<1][MN<<1],pw[MN<<1];
inline ll solve(int i,int n){
	reg int k2=min(k-i/2,(i-1)/2);reg int k1=k-(k2<<1)-((i&1)==0);
	reg ll res=0,pos=1;
	for(reg int j=k2;j+k1>0&&j>=0;j--,pos*=-1)
		res+=pos*C[j+k1+n-1][j+k1-1]*pw[j]%mod*C[k2][j]%mod,
		res%=mod;
	return (res+mod)%mod;
}
int main(){
	cin>>k>>n;C[0][0]=1;pw[0]=1;
	F(i,1,4000){
		C[i][0]=1;pw[i]=(pw[i-1]+pw[i-1])%mod;F(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	reg ll ans=0;
	F(i,2,k<<1){
		if(~i&1)ans=(solve(i,n)+solve(i,n-1))%mod;
		else ans=solve(i,n);
		printf("%lld\n",ans);
	}
	return 0;
}