#include <bits/stdc++.h>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;


template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;

using P=pair<ll,pair<ll,ll>>;
void solve(){
	ll n;
	cin>>n;
	vector<P>p(n);
	rep(i,n){
		cin>>p[i].second.first>>p[i].second.second;
		p[i].first=p[i].second.second-p[i].second.first;
	}
	sort(all(p));
	ll ans=0;
	vector<ll>val(n+1),rval(n+1);
	ll left=0,right=1e9;
	rep(i,n){
		chmax(left,p[i].second.first);
		chmin(right,p[i].second.second);
		val[i+1]=right-left+1;
	}
	left=0,right=1e9;
	for(int i=n-1;i>=0;--i){
		chmax(left,p[i].second.first);
		chmin(right,p[i].second.second);
		rval[i]=right-left+1;
	}
	REP(i,1,n){
		//cout<<val[i]<<" "<<rval[i]<<"\n";
		chmax(ans,max(val[i],0LL)+max(rval[i],0LL));
	}
	rep(i,n)p[i].first=0;
	sort(all(p));
	left=0,right=1e9;
	rep(i,n){
		chmax(left,p[i].second.first);
		chmin(right,p[i].second.second);
		val[i+1]=right-left+1;
	}
	left=0,right=1e9;
	for(int i=n-1;i>=0;--i){
		chmax(left,p[i].second.first);
		chmin(right,p[i].second.second);
		rval[i]=right-left+1;
	}
	REP(i,1,n){
		//cout<<val[i]<<" "<<rval[i]<<"\n";
		chmax(ans,max(val[i],0LL)+max(rval[i],0LL));
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
