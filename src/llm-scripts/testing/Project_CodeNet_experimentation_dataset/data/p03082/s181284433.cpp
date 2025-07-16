#include<bits/stdc++.h>
using namespace std;


// type definitions
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef complex<int> ci;
typedef complex<double> cd;
typedef complex<long double> cld;
typedef long double ld;

// macros
#define rep(i, a, b) for(int i=a; i<b; i++)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define all(c) c.begin(), c.end()
#define tr(c, it) for(auto it=(c).begin(); it!=c.end(); it++)
#define PB push_back
#define MP make_pair
#define bitcount __builtin_popcount
#define watch(x) cerr<< (#x) << " is " << (x) <<"\n";
#define sz(x) ((int)((x).size()))
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
#define pii2ll(p) ((ll)(p).first<<32 | (p).second)

// template functions
template <typename T>
inline void printV(vector<T>& a) { rep(i, 0, sz(a)) { cout<<a[i]<<" "; } cout<<"\n"; }
template <typename T>
inline void printV(vector<T>& a, int n) { rep(i, 0, n) { cout<<a[i]<<" "; } cout<<"\n"; }
template <typename T>
inline void printVV(vector<vector<T>>& a)
{
	rep(i, 0, sz(a)) {
		printV(a[i]);
	}
	cout<<"\n";
}

template <typename T>
inline void clearVV(vector<vector<T>>& a)
{
	for(auto& x:a) {
		x.clear();
	}
	a.clear();
}
template <typename T>
inline void assignVV(vector<vector<T>> &a, T val)
{
	for(int i=0; i<sz(a); i++) {
		for(int j=0; j<sz(a[i]); j++) {
			a[i][j]=val;
		}
	}
}

// random number generation
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// constants
const long double eps = LDBL_EPSILON;
const int inf = 5e8;
const int modn = 1e9+7;
const int MAX = 1e5;

inline int add(int a, int b)
{
	int ret=((ll)a+b)%modn;
	if(ret<0) {
		ret=(ret+modn)%modn;
	}
	return ret;
}

inline int mul(int a, int b)
{
	int ret=((ll)a*b)%modn;
	if(ret<0) {
		ret=(ret+modn)%modn;
	}
	return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
	int N, X;
	cin>>N>>X;
	vector<int> a(N+1);
	for(int i=1; i<=N; i++) {
		cin>>a[i];
	}
	sort(all(a));
	vector<vector<int>> dp(N+1, vector<int>(X+1, -1));
	function<int(int, int)> solve = [&](int n, int x)
	{
		if(n==1) {
			return x%a[n];
		}
		
		int &memo = dp[n][x];
		if(memo!=-1) return memo;
		
		int ans = 0;
		ans = add(ans, solve(n-1, x%a[n]));
		ans = add(ans, mul(n-1, solve(n-1, x)));
		return memo=ans; 
	};
	int ans = solve(N, X);
	cout<<ans<<"\n";
    return 0;
}


