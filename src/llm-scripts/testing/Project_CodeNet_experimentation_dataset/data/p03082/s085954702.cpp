/*input
10 100000
50000 50001 50002 50003 50004 50005 50006 50007 50008 50009
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=100005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}

ll inv[maxn];
ll dp[maxn];
int p[maxn];
int main(){
	IOS;
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++) inv[i]=mypow(i,MOD-2);
	REP(i,n) cin>>p[i];
	sort(p,p+n);

	dp[x]=1;
	for(int i=1;i<=n;i++) dp[x]=dp[x]*i%MOD;
	for(int i=n-1;i>=0;i--){
		if(i==0){
			REP(j,x+1) if(j>=p[i]){
				dp[j%p[i]]=(dp[j%p[i]]+dp[j])%MOD;
				dp[j]=0;
			}
		}
		else{
			REP(j,x+1) dp[j]=dp[j]*i%MOD*inv[i+1]%MOD;
			REP(j,x+1) dp[j%p[i]]=(dp[j%p[i]]+dp[j]*inv[i])%MOD;
		}
		// for(int i=0;i<=x;i++) cout<<dp[i]<<" \n"[i==x];
	}
	ll ans=0;
	REP(i,x+1){
		ans+=dp[i]*i%MOD;
		if(ans>=MOD) ans-=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}
