#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int
#define ld long double

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10
#define PI acos(-1LL)


int MOD = 1e9 + 7;

inline int mul(int a,int b,int mod=MOD){return ((a%mod)*(b%mod))%mod;}
inline int sum(int a,int b,int mod=MOD){return ((a%mod)+(b%mod))%mod;}
int power(int a,int n,int mod=MOD){int ans=1;while(n){if(n&1)ans=mul(ans,a,mod);a=mul(a,a,mod);n>>=1;}return ans;}
inline int sub(int a,int b,int mod=MOD){ return (((a) % mod)-((b) % mod) + mod) % mod; }
int inv[1000006];
void find_inverse(int m)  //m should be prime..
{
	inv[1] = 1;
	for(int i = 2; i < m; ++i)
    	inv[i] = (m - (m/i) * inv[m%i] % m) % m;
}

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();

int32_t main()
{
    #ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif 

    fast
    
    int t = 1;
	// cin>>t;
	
	while(t--)
	    solve();
	return 0;  
}

void solve()
{
	int i,j;
	int n;
	cin>>n;

	vector<int>a(n);

	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int ans=0;

	for(i=0;i<60;i++)
	{
		int cnt=0;
		for(j=0;j<n;j++)
		{
			if(a[j]&(1LL<<i))
			{
				cnt++;
			}
		}

		int one=cnt;
		int zero=n-cnt;

		ans=sum(ans,mul(power(2,i),mul(one,zero)));
	}

	cout<<ans<<endl;
	

}