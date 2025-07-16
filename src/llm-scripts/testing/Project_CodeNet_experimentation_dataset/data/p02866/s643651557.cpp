#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)x.size())
#define MOD (ll)(998244353)
#define INF (9e18)
#define EPS (1e-6)
#ifdef LOCAL_TEST
#define debug(...) do{\
	cerr<<__PRETTY_FUNCTION__<<" - "<<__LINE__<<\
	" : ("#__VA_ARGS__<<") = ";\
	_OUT(__VA_ARGS__);\
}while(0)
template<typename T>void _OUT(T x){cerr<<x<<endl;}
template<typename T,typename...I>void _OUT(T x,I ...tail){cerr<<x<<", ";_OUT(tail...);}
#else
#define debug(...)
#endif

void INIT(){
#ifdef LOCAL_TEST
	freopen("D:\\input.in","r",stdin);
	freopen("D:\\output.out","w",stdout);
	freopen("D:\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll fpow(ll b,ll p){
	b%=MOD;
	ll ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int32_t main() {
	INIT();
	//code...
	int n; cin>>n;
	vector<int> cnt(n,0);
	int t; cin>>t;
	if(t!=0){
		cout<<"0\n";
		return 0;
	}
	cnt[0]++;
	For(i,1,n-1){
		cin>>t;
		if(t==0){
			cout<<"0\n";
			return 0;
		}
		cnt[t]++;
	}
	int now=1;
	ll ans=1;
	For(i,1,n-1){
		if(cnt[i]==0 && now!=n){
			cout<<"0\n";
			return 0;
		}
		ans=(ans*fpow(cnt[i-1],cnt[i]))%MOD;
		now+=cnt[i];
	}
	cout<<ans<<"\n";
	return 0;
}
