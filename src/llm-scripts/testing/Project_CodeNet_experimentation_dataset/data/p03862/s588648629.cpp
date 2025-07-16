#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree < pairs ,  null_type , greater<pairs>,  rb_tree_tag ,  tree_order_statistics_node_update > 
#define ll long long
#define lld long double
#define vc vector<ll>
const ll MOD=(1e9 +7);
typedef pair<ll,ll>pairs;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
    return res;}

int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t,n,i,j,k,l,c,f;
	cin>>n>>k;
	ll temp;
	vc a(n+1);
	for(i=1;i<=n;i++)cin>>a[i];
	ll ans=0;
	for(i=1;i<n;i++)
	{
	    temp=a[i]+a[i+1];
	    if(temp>k)
	    {
	        if(a[i+1]>=(temp-k))
	            a[i+1]-=(temp-k);
	        else
	            a[i+1]=0;
	        ans+=temp-k;
	    }
	}
	cout<<ans;
	return 0;
}
