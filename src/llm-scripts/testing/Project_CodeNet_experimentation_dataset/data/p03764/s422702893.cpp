/*-- ILSH  --*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back 
#define pop pop_back
#define mp make_pair
#define vii vector < int >
#define vll vector < ll > 
#define dt cout<<"HERE\n";
#define pii pair < int , int >
#define pll pair < ll , ll >
#define vpi vector < pll >
#define vpl vector < pll >
#define fi first
#define se second 
#define sz size 
#define len length 

const ll inf=1e18+1e17;
const ll mod =1e9+7;
//const ll mod = 998244353;

ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}  
ll powm(ll a,ll b){a=a%mod;ll res=1;while(b){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return (res%mod);}


const ll N =5e5+5;



void solve(){
	ll n,m;
	cin>>n>>m;
	ll arr[n], brr[m],crr[n],drr[m];
	for ( int i=0;i<n;i++)
		cin>>arr[i];
	for ( int j=0;j<m;j++)
		cin>>brr[j];
	for ( int i=1;i<n;i++){
		crr[i]=arr[i]-arr[i-1];
	}
	for ( int i=1;i<m;i++)
		drr[i]=brr[i]-brr[i-1];
	for ( int i=2;i<n;i++)
		crr[i]=(crr[i]*i+crr[i-1])%mod;
	for ( int i=2;i<m;i++)
		drr[i]=(drr[i]*i+drr[i-1])%mod;
	ll tot1=0,tot2=0,ans=0;
	for ( int i=1;i<n;i++)
		tot1=tot1+crr[i];
	for ( int j=1;j<m;j++)
		tot2=tot2+drr[j];
	tot2=tot2%mod;
	tot1=tot1%mod;
	ans=(tot1*tot2)%mod;
	cout<<ans<<'\n';

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie( NULL);
	cout.tie(NULL);
	// #ifndef
	// 	freopen( "INPUT.txt", "r" , stdin);
	// 	freopen( "OUTPUT.txt","w", stdout);
	// #endif

	int t=1;

	//cin>>t;

	for ( int i=1;i<=t;i++){
   // 	cout<<"Case #"<<i<<": ";
    	solve();
 	}
}