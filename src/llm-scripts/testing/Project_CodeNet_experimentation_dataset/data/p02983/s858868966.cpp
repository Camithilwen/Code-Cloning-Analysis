#include<bits/stdc++.h>

using namespace std;
using   ll=long long;

#define fast        	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define endl        	"\n"
#define pb          	push_back
#define mp          	make_pair
#define F           	first
#define S           	second
#define int             long long int
#define pll				pair<int , int>

#define ALL(v)      	v.begin(),v.end()
#define ALLR(v)     	v.rbegin(),v.rend()
#define pii         	3.14159265358979323
#define inf     		LLONG_MAX
#define ones(x)     	__builtin_popcount(x)
#define fill(a,b)   	memset(a,b,sizeof(a))
#define mod 			1000000007
#define hell            998244353 

ll mod_pow(ll a,ll b,ll m) 
{
    ll res = 1;
    while(b)	
    {
        if(b&1) 	
        {
        	res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

ll mod_inverse(ll a) 
{
	return mod_pow(a , mod-2 , mod);
}

void solve() 
{
	int  l , r;
	
	cin >> l >> r;
	
	int lol = 2019;
	
	int ans = inf;
	
	for(int i = 1; i <= 2019; ++i) {
		int num = (l/2019)*2019;
		
		num += i;
		
		if(num < l) {
			num += 2019;
		}
		
		//cout << num << endl;
		
		if(num > r) {
			continue;
		}
		
		for(int j = 1; j <= 2019; ++j) {
			int tm;
			if(i == j) {
				tm = num + 2019;
			}
			else {
			tm = (l/2019)*2019;
			
			tm += j;
			
			if(tm < l) {
				tm += 2019;
			}
		
			}
			
			if(num >= l && num <= r && tm >= l && tm <= r) {
				ans = min(ans , (num*tm)%2019);
			}
		}
	}
	
	cout << ans;
}

signed main() {
    fast;
    
    int t = 1;
    
	//cin >> t;
    
    while(t--) {
        solve();
    }
 
    return 0;
}
