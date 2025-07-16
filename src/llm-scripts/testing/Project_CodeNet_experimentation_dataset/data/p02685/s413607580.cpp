#include<bits/stdc++.h>
#define ll long long int
#define mod 998244353
#define ld long double
#define pb push_back
#define inf INT_MAX
#define N 1000000
using namespace std;
int n,m,k;
ll ans=0;
ll inv[N+3];
ll fact_inv[N+3];
ll fact[N+3];
//modulo inverse 
void inverse(){
	inv[1]=1;//MMI
	int i;
	for(i=2;i<=N;i++){
		inv[i]=mod-(mod/i)*inv[mod%i]%mod;
	}
}
void factinv(){
	int i;
	fact_inv[0]=1;
	for(i=1;i<=N;i++){
		fact_inv[i]=fact_inv[i-1]*inv[i]%mod;
	}
}
void facto(){
	int i;
	fact[0]=1;
	for(i=1;i<=N;i++){
		fact[i]=(fact[i-1]*i)%mod;
	}
}
ll power(int a,int b){
	if(b==0)
	return 1;
	else if(b==1)
	return a;
	else{
		if(b&1)
		return ((a%mod)*(power(a,b-1)%mod))%mod;
		else
		return ((power(a,b/2)%mod)*(power(a,b/2)%mod))%mod;
	}
}
void solve(int p){
	ll a=((fact_inv[n-p-1]%mod)*(fact_inv[p]%mod))%mod;
	ll b=(m*power(m-1,n-p-1)%mod)%mod;
	ll c=(a*b)%mod;
	ans+=(fact[n-1]*c)%mod;
	ans%=mod;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	cin>>n>>m>>k;
	facto();
	inverse();
	factinv();
	//cout<<inv[123]<<endl;
	for(i=0;i<=k;i++)
	solve(i);
	cout<<ans<<endl;
}
