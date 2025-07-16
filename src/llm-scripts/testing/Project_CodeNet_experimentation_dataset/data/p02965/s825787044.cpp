#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=998244353;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

ll ppow(ll a,ll b){
	a%=MOD;
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
class Fact{
	vector<ll>fact;
	vector<ll>inv;
public:
	Fact(){}
	Fact(int n){
		n=n*2+10;
		fact=inv=vector<ll>(n);
		fact[0]=inv[0]=1;
		for(int i=1;i<n;i++){
			fact[i]=(fact[i-1]*i)%MOD;
		}
		inv[n-1]=ppow(fact[n-1],MOD-2);
		for(int i=n-2;i>=0;i--){
			inv[i]=(inv[i+1]*(i+1))%MOD;
		}
	}
	ll get(int n){
		return fact[n];
	}
	ll get_inv(int n){
		return inv[n];
	}
	ll nPr(int n,int r){
		return fact[n]*inv[n-r]%MOD;
	}
	ll nCr(int n,int r){
		return nPr(n,r)*inv[r]%MOD;
	}
	ll nrP(int n,int r){
		return nPr(n+r,n);
	}
	ll nrC(int n,int r){
		return nCr(n+r,n);
	}
};

int main(){
	int n,m;cin>>n>>m;
	Fact fac(3*m+n);
	ll ans=0;
	for(int s=m%2;s<=min(n,m);s+=2){
		ll a=fac.nCr(n,s);
		ll b=fac.nCr((3*m-s)/2+n-1,n-1);
		if((3*m-s)/2>=m)(b+=MOD-fac.nCr((3*m-s)/2-m+n-1,n-1)*s%MOD)%=MOD;
		if((3*m-s)/2>=m+1)(b+=MOD-fac.nCr((3*m-s)/2-m-1+n-1,n-1)*(n-s)%MOD)%=MOD;
		(ans+=a*b)%=MOD;
	}
	cout<<ans<<endl;
}