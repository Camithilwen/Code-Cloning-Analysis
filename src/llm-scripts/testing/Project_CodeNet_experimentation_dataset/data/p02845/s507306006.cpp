#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void amin(ll &a, ll b){ a=min(a,b); }
void amax(ll &a, ll b){ a=max(a,b); }
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
const ll INF = ll(1e18);
const int MOD = 1e9+7;

ll add(ll a,ll b)
{
	a%=MOD; b%=MOD;
	a+=b;a%=MOD;
	if(a<0) a+=MOD;
	return a;
}
ll mult(ll a, ll b)
{
	a%=MOD; b%=MOD;
	ll ans=(a*b)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}
ll pw(ll a, ll b)
{
	ll r=1;
	while(b){
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
ll inverse(ll a)
{
	return pw(a,MOD-2);
}
const int MAXN = 100005;

void NO(){ cout<<0<<'\n'; exit(0); }

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n; cin>>n;
	int a[n];
	forn(i,0,n) cin>>a[i];
	
	int c[3]{};
	ll ans=1;
	
	forn(i,0,n){
		int cnt=0;
		forn(j,0,3){
			if(a[i]==c[j]) cnt++;
		}
		ans=mult(ans,cnt);
		forn(j,0,3){
			if(a[i]==c[j]){ c[j]++; break; }
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
