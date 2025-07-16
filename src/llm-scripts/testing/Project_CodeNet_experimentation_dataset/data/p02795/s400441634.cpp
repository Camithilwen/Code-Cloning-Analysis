#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)

#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pi pair<ll,ll>
#define pii pair<ll,pi >
#define ppi pair<pi,ll>
#define ppp pair<pi,pi >
#define ex(str,a,b) str.substr((int)(a),min((int)str.size()-a,(int)(b-a+1))) 
#define all(X) X.begin(),X.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// for pair comparison function(ascending order) use return (i1.ff < i2.ff);

/* string operations :
   str.substr (x,y) : returns a substring str[x],str[x+1],...str[x+y-1]
   __builtin_popcount(n) : no. of set bits in n.
*/

const int M = (1<<20)+5;
const int md = 1e9+7;

priority_queue<ll,vector<ll >,greater<ll > > pq;

ll pwr(ll a,ll n,ll m)
{
	ll p=1;
	while(n>0)
	{
		if(n%2==1)
			p=(p*a)%m;
		a=(a*a)%m;
		n=n/2;
	}
	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,h,w;
	cin >> h >> w >> n;
	if(h>w)
		cout << (n+h-1)/h << "\n";
	else
		cout << (n+w-1)/w << "\n";
}
	