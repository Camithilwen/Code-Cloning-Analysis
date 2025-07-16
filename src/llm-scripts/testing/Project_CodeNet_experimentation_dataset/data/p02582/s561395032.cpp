
	
	
	
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"	
	typedef long long LL;
	#define ld long double
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define mod2 998244353
	#define INFINITE 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define sz(v) ((ll)(v).size())
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define pb push_back
	#define f first
	#define s second
	#define dbg(a) cout<<#a<<" --> "<<(a)<<"\n";
	#define forn(i,n) for (ll i=0; i<(n); ++i)
	#define fornd(i,n) for (ll i=(n)-1; i>=0; --i)	
	#define forab(i,a,b) for (ll i=(a); i<=(b); ++i)
	#define read(a) ll a; cin >> a;
	#define reads(s) string s; cin >> s;
	#define readb(a, b) ll a, b; cin >> a >> b;
	#define readc(a, b, c) ll a, b, c; cin >> a >> b >> c;
	#define readarr(a, n) int a[(n) + 1] = {}; forab(i, 0, (n-1)) {cin >> a[i];}
	#define readmat(a, n, m) int a[n + 1][m + 1] = {}; forab(i, 1, n) {forab(j, 1, m) cin >> a[i][j];}
	#define readv(A,n) vll A(n,0); forn(i,n) cin>>A[i]; 
	#define print(a) cout << a << endl;
	#define printarr(a, n) forab (i, 1, n) cout << a[i] << " "; cout << endl;
	#define printv(v) for (int i: v) cout << i << " "; cout << endl;
	#define printmat(a, n, m) forab(i, 1, n) {forab (j, 1, m) cout << a[i][j] << " "; cout << endl;}
	#define precision(a) cout<<fixed<<setprecision(a);
	#define INF (1e18+5)
	#define inf (1e9+5)
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	// 8-directions
	//int dx[]={1,1,1,0,0,-1,-1,-1};
	//int dy[]={-1,0,1,-1,1,-1,0,1};
	#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
	using namespace std;
	int begtime = clock();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	mt19937_64 rngb(chrono::steady_clock::now().time_since_epoch().count()); // can give negative values too
	bool isPowerOfTwo(int x) {
    return x && (!(x & (x - 1)));
	}
	int takemod(int x) {
    return (x % mod + mod) % mod;
	}
 
	int fpow(int base, int power, int MOD) {
    int result = 1;
    base = base % MOD;
    while (power) {
        if (power & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        power = power >> 1;
    }
    return result;
	}
 
	int modinv(int x) {return fpow(x, mod - 2, mod);}
	void solve()
	{
		string a;
		cin>>a;
		ll ans=0;
		if(a[0]=='R'&&a[1]=='R'&&a[2]=='R')
		{
			cout<<3<<endl;
		}
		else if((a[0]=='R'&&a[1]=='R')||(a[1]=='R'&&a[2]=='R'))
		{
			cout<<2<<endl;
		}
		else if(a[0]=='R'||a[1]=='R'||a[2]=='R')
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	int main()
	{	
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
		fast_io;
		int T=1;
		//cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			solve();
		}
		#ifndef ONLINE_JUDGE
    		cerr << "Time elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
    		#endif
		return 0;
	}

	
	
	
	