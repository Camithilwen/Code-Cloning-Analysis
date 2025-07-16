#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
//datatypes
	#define ll 			long long
	#define vi 			vector<int>
	#define vll 		vector<ll>
	#define si 			set<int>
	#define vii 		vector<ii>
	#define ii 			pair<int,int>
	#define vpll		vector<pll>
	#define pii 		pair<int,int>
	#define pll 		pair<ll, ll>
	#define mii 		map<int,int>
	#define ord_set		tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
	#define M 			1000000007
	#define narak 		998244353
	#define pi 			acos(-1)
	#define inf 		2147483647
	#define infl 		9223372036854775807
	#define infd 		1.7e308
	#define invd 		1.7e-308
	#define sz(x) 		(ll)x.size()
	#define fr 			first
	#define sc 			second
	#define pb 			push_back
	#define mkp 		make_pair
	#define rep(i,a,b) 	for(int i=a; i<b; ++i)
	#define rep0(i,a)	for(int i=0; i<a; ++i)
	#define rep1(i,a)	for(int i=1; i<=a; ++i)
	#define trav(a) 	for(auto &x:a)
	#define test 		cout<<"hello\n";
	#define all(x) 		(x).begin(),(x).end()
	#define mem(x,val)	memset(x, val, sizeof(x))
	#define sa(x) 		std::sort(all(x))
	#define endl 		'\n'
	#define __lcm(m,n) 	m*(n/__gcd(m,n))
	#define fill(a,n) 	for(int xxx=0;xxx<n;++xxx) cin>>(a)[xxx]
	#define maxa(v)		*(max_element(all(v)))
	#define mina(v)		*(min_element(all(v))
	#define inputFile 	freopen("input.txt", "r", stdin); 
	#define outputFile	freopen("output.txt", "w", stdout);
	#define disp(a) 	trav(a) cout<<x<<" "; cout<<endl;
  	//#define int long long

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T,typename U> std::ostream& operator<<(std::ostream& out, std::pair<T,U> a) {out<<a.fr<<" "<<a.sc; return out;}
template<typename T,typename U> std::istream& operator>>(std::istream& in, std::pair<T,U> &a) {in>>a.fr>>a.sc; return in;}
template<typename T> static inline void sd(vector<T> &x) {sort(all(x), greater<T>()) ; }
const int N=301;
int n;
double dp[N][N][N]={};

signed solve()
{
	cin>>n;
    int cnt[4]={};
    rep(i,0,n){int x;
    	cin>>x;
    	cnt[x]++;
    }
    dp[0][0][0]=0;
    for(int three=0; three<=n; ++three)
    {
    	for(int two=0; two<=n; ++two)
    	{
    		for(int one=0; one<=n; ++one)
    		{
    			int zero = n -(three+two+one);
    			if(zero == n)
    				continue;
    			if(three+two+one > n)
    				continue;
    			double val = 1;
    			if(three>0)
    			val += (1.0*three/n)*(dp[three-1][two+1][one]);
    			if(two>0)
    			val += (1.0*two/n)*(dp[three][two-1][one+1]);
    			if(one>0)
    			val += (1.0*one/n)*(dp[three][two][one-1]);
    			val /= (1.0-1.0*zero/n);
    			dp[three][two][one] = val;
    		}
    	}
    }
    cout<<fixed<<setprecision(12)<<dp[cnt[3]][cnt[2]][cnt[1]];
	return 0;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)
	{
        
		solve();
        
	}
	//cout << "\nTime : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}