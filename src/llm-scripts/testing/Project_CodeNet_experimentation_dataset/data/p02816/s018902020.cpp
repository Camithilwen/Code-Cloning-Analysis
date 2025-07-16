#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;

template<class T> inline void checkmin(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,const T &b){if(b>a) a=b;}

const int inf=1e9+10;
const int maxn=2e5+10;

const ll base=1e9+7;
const ll mod=2038077799;

ll ha,hb,a[maxn],b[maxn],difa[maxn],difb[maxn];
int n; 

ll getval(ll x,ll k,ll mod){
	if(k==0) return 1ll;
	if(k==1) return x;
	ll res=getval(x,k/2,mod);
	res=(res*res)%mod;
	if(k&1) res=(res*x)%mod;
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<n;i++) scanf("%lld",&b[i]);
	for(int i=0;i<n;i++) difa[i]=a[i]^a[(i+1)%n];
	for(int i=0;i<n;i++) difb[i]=b[i]^b[(i+1)%n];
	ha=hb=0;
	for(int i=0;i<n;i++){
		ha*=base; ha%=mod;
		ha+=difa[i]; ha%=mod;
	}
	for(int i=0;i<n;i++){
		hb*=base; hb%=mod;
		hb+=difb[i]; hb%=mod;
	}
	ll val=getval(base,n-1,mod);
	vector <int> ans;
	for(int i=0;i<n;i++){
		if(ha==hb){
			ans.pb(i);  
		}
		ll now=val*difa[i]; now%=mod;
		ha+=mod-now; ha%=mod;
		ha*=base; ha%=mod;
		ha+=difa[i]; ha%=mod; 
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" "<<(a[0]^b[(n-ans[i])%n])<<endl;
	}
	return 0;
}
