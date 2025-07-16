#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define pii pair<ll,ll>
#define inf 1000000000000000000
#define bpc(x) __builtin_popcountll(x)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

ll powa(ll a, ll b, ll c)
{
    a%=c;
    if(a<0)
	a+=c;
    ll res = 1;
    while(b>0)
    {
        if(b&1)
            res*=a, res%=c;
        a*=a, a%=c;
        b>>=1;
    }
    return res;
}
int main()
{
  FAST/**/
   
   ll n;
   cin>>n;
   
   ll arr[n];
   ll sum = 0;
   rep(n)
        cin>>arr[i], sum+=arr[i], sum%=mod;
   
   sum = (sum*sum)%mod;
   
   rep(n)
       sum = (sum-((arr[i]*arr[i])%mod)+mod)%mod;
   sum*=powa(2,mod-2,mod);
   sum%=mod;
   cout<<sum;
   
   return 0;        
}  

  
          
   