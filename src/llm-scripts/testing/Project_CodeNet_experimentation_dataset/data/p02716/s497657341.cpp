/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ld long double
#define zero(a) memset((a),0,sizeof((a)))
#define one(a) memset((a),1,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)))
#define all(g) g.begin(),g.end()
#define ppb pop_back
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
const ll INF=1e16;
vector<ll>v(200005,-INF);
ll dp[200005][2][2];
bool vis[200005][2][2];
ll n;
ll find(ll pos,ll flag1,ll flag2){
	// cout<<pos<<" "<<flag1<<" "<<flag2<<endl;
	if(pos>=n) return 0ll;
	ll &ans=dp[pos][flag1][flag2];
	if(vis[pos][flag1][flag2]) return ans;
	vis[pos][flag1][flag2]=1;
	if(flag2==0){
		if(pos==n-3){
			if(flag1==0) return ans=max(v[pos],max(v[pos+1],v[pos+2]));
			else         return ans=max(v[pos+1],v[pos+2]);
		}
		if(flag1==0){
			ll ans1=find(pos+2,0ll,1ll);
			ll ans2=v[pos]+find(pos+2,0ll,0ll);
			ll ans3=v[pos+1]+find(pos+2,1ll,0ll);
			ans=max(ans1,max(ans2,ans3));
		}
		else{
			ll ans1=find(pos+2,0ll,1ll);
			ll ans2=v[pos+1]+find(pos+2,1ll,0ll);
			ans=max(ans1,ans2);
		}
	}
	else{
		if(flag1==0){
			ll ans1=v[pos]+find(pos+2,0ll,1ll);
			ll ans2=v[pos+1]+find(pos+2,1ll,1ll);
			ans=max(ans1,ans2);
		}
		else{
			ans=v[pos+1]+find(pos+2,1ll,1ll);
		}	
	}
	// cout<<pos<<" "<<flag1<<" "<<flag2<<" "<<ans<<endl;
	return ans;
} 
int main(){
	FastRead;
	ll t=1;
	while(t--){
		cin>>n;
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}
		for(ll i=0;i<n;i++){
			vis[i][0][0]=vis[i][0][1]=0;
			vis[i][1][0]=vis[i][1][1]=0;
		}
		if(n&1){
			cout<<find(0,0ll,0ll)<<endl;
		}
		else{
			cout<<find(0,0ll,1ll)<<endl;
		}
	}
}