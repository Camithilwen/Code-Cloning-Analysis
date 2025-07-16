/*input
5 1
5
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
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
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
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

vector<int> odd,even;
int a[maxn];
vector<int> ans;
int main()
{
	IOS;
	int n,m;
	cin>>n>>m;
	REP(i,m) cin>>a[i];

	REP(i,m){
		if(a[i]%2) odd.pb(a[i]);
		else even.pb(a[i]);
	}
	if(SZ(odd)>2){
		cout<<"Impossible\n";
		return 0;
	}

	if(SZ(odd)==0){
		REP(i,SZ(even)) cout<<even[i]<<" \n"[i==SZ(even)-1];
		ans.pb(1);
		REP(i,SZ(even)-1) ans.pb(even[i]);
		ans.pb(even.back()-1);
	}
	else if(SZ(odd)==1&&SZ(even)){
		cout<<odd[0];
		for(int i:even) cout<<' '<<i;
		cout<<'\n';
		ans.pb(odd[0]+1);
		REP(i,SZ(even)-1) ans.pb(even[i]);
		if(SZ(even)) ans.pb(even.back()-1);
	}
	else if(SZ(odd)==1){
		cout<<odd[0]<<'\n';
		if(odd[0]-1) ans.pb(odd[0]-1);
		ans.pb(1);
	}
	else{
		cout<<odd[0];
		for(int i:even) cout<<' '<<i;
		cout<<' '<<odd[1]<<'\n';

		ans.pb(odd[0]+1);
		for(int i:even) ans.pb(i);
		if(odd[1]-1) ans.pb(odd[1]-1);
	}
	cout<<SZ(ans)<<'\n';
	for(int i:ans) cout<<i<<' ';
	cout<<'\n';
	return 0;
}
