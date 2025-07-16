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

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int q;
	cin>>q;
	vector<ll>cnt_m(n+1);
	rep(i,n){
		cnt_m[i+1]=cnt_m[i]+ll(s[i]=='M');
	}
	while(q--){
		int k;
		cin>>k;
		vector<vector<ll>>dp(2,vector<ll>(4));
		dp[0][0]=1;
		rep(i,k){
			rep(j,4){
				dp[(i+1)%2][j]+=dp[i%2][j];
			}
			if(s[i]=='D'){
				dp[(i+1)%2][1]+=dp[i%2][0];
			}
			else if(s[i]=='M'){
				dp[(i+1)%2][2]+=dp[i%2][1];
			}
			else if(s[i]=='C'){
				dp[(i+1)%2][3]+=dp[i%2][2];
			}
			rep(j,4)dp[i%2][j]=0;
		}
		for(int i=k;i<n;++i){
			if(s[i-k]=='D'){
				dp[i%2][2]-=(cnt_m[i]-cnt_m[i+1-k]);
				dp[i%2][1]--;
			}
			rep(j,4){
				dp[(i+1)%2][j]+=dp[i%2][j];
			}
			if(s[i]=='D'){
				dp[(i+1)%2][1]+=dp[i%2][0];
			}
			else if(s[i]=='M'){
				dp[(i+1)%2][2]+=dp[i%2][1];
			}
			else if(s[i]=='C'){
				dp[(i+1)%2][3]+=dp[i%2][2];
			}
			rep(j,4)dp[i%2][j]=0;
		}
		cout<<dp[n%2][3]<<"\n";
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
