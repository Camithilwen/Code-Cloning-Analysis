#include <iostream>
using namespace std;
typedef long long ll;

const ll M=1000005,mod=998244353;
ll F[M];

void Init(){
	F[0]=1;
	for(int i=1;i<M;i++) F[i]=F[i-1]*i%mod;
}

ll Pow(ll n,ll p){
	ll r=1;
	for(;p>0;p>>=1){
		if(p&1) r=(r*n)%mod;
		n=(n*n)%mod;
	}
	return r;
}

ll Div(ll n,ll m){
	return n*Pow(m,mod-2)%mod;
}

ll nCk(ll n,ll k){
	return Div(F[n],F[n-k]*F[k]%mod);
}

int n,m;

int main(){
	Init();
	cin>>n>>m;
	if(n>m) swap(n,m);
	ll t=0;
	for(int i=0;i<n;i++) (t+=nCk(2*i+1,i)*nCk(n+m-2*i-2,n-i-1))%=mod;
	cout<<(m+Div(t,nCk(n+m,n)))%mod<<endl;
}