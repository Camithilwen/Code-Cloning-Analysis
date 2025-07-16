#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int mod=1e9+7; 
int inv[200005],finv[200005],f[200005];
void C(){
	f[0]=1;finv[0]=1;finv[1]=1;f[1]=1;inv[1]=1;
	FOR(i,2,200000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod; 
	}
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	C();
	int sum,ans=0,t=n*m;
	FOR(i,1,n){
		FOR(j,1,m){
			sum=0;
			int t1=i-1,t2=j-1;
			sum=sum+t1*(t1+1)/2%mod*m+t2*(t2+1)/2%mod*n;sum=sum%mod;
			t1=n-t1-1;t2=m-t2-1;
			sum=sum+t1*(t1+1)/2%mod*m+t2*(t2+1)/2%mod*n;sum=sum%mod;
			sum=sum*inv[t-1]%mod*f[t-1]%mod*finv[t-k]%mod*finv[k-2]%mod;
			ans=(ans+sum)%mod;
		}
	} 
	cout<<ans*inv[2]%mod;
	RE 0;
}


