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


void solve()
{
	int n;
	cin>>n;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	vector<ll>sum(n+1);
	rep(i,n){
		sum[i+1]=sum[i]+a[i];
	}
	ll ans=INF;
	for(int i=1;i<n-2;++i){
		vector<ll>left(4),right(4);
		int ok=1,ng=i+1;
		while(abs(ok-ng)>1){
			int mid=(ok+ng)/2;
			if(sum[i+1]-sum[mid]>sum[mid])ok=mid;
			else ng=mid; 
		}
		left[0]=sum[ok],right[0]=sum[i+1]-sum[ok];
		// ok=1,ng=i+1;
		// while(abs(ok-ng)>1){
		// 	int mid=(ok+ng)/2;
		// 	if(sum[i+1]-sum[mid]<sum[mid])ok=mid;
		// 	else ng=mid; 
		// }
		left[1]=sum[ng],right[1]=sum[i+1]-sum[ng];
		ok=i+2,ng=n;
		while(abs(ok-ng)>1){
			int mid=(ok+ng)/2;
			if(sum[n]-sum[mid]>sum[mid]-sum[i+1])ok=mid;
			else ng=mid; 
		}
		left[2]=sum[ok]-sum[i+1],right[2]=sum[n]-sum[ok];
		// ok=i+2,ng=n;
		// while(abs(ok-ng)>1){
		// 	int mid=(ok+ng)/2;
		// 	if(sum[n]-sum[mid]<sum[mid]-sum[i+1])ok=mid;
		// 	else ng=mid; 
		// }
		left[3]=sum[ng]-sum[i+1],right[3]=sum[n]-sum[ng];
		rep(j,2){
			REP(k,2,4){
				//cout<<left[j]<<" "<<right[j]<<" "<<left[k]<<" "<<right[k]<<"\n";
				chmin(ans,max({left[j],right[j],left[k],right[k]})-min({left[j],right[j],left[k],right[k]}));
			}
		}
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
