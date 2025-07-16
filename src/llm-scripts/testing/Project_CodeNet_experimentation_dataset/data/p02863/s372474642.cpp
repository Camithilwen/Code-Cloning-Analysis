#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define D 1000000000ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI 3.14159265358979323
#define subt cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n"

ll dp[7007];

int main() 
{
    FAST;
    ll n,t;
    cin>>n>>t;
    pair<ll,ll> a[n];
    ll x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        a[i]={x,y};
    }
    sort(a,a+n);
    for(int i=1;i<7007;i++)
        dp[i]=-1;
    for(int i=0;i<n;i++)
        for(int j=t-1;j>=0;j--)
            if(dp[j]!=-1)
                dp[a[i].first+j]=max(dp[a[i].first+j],dp[j]+a[i].second);
    ll ans=0;
    for(int i=0;i<7007;i++)
        ans=max(ans,dp[i]);
    cout<<ans;
    subt;   
    return 0;
}