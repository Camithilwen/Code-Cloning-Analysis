#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf 1e18
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mod 1000000007
#define pb push_back
#define all(s) s.begin(),s.end()
#define pie 3.14159265358979323846
#define fr(i,a,b)  for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=b-1;i>=a;i--)
#define gcd __gcd
#define con continue
#define pii pair<ll,ll>
signed main(){
    FASTIO;
    ll tt=1;
    //cin>>tt;
    while(tt--){
         ll n;cin>>n;
         ll arr[n],sum=0;
         ll a[n],s=0;
         for(ll i=0;i<n;i++)cin>>a[i];
         for(ll i=n-1;i>=0;i--)s+=a[i],arr[i]=s,s%=mod;
         //for(ll i=0;i<n;i++)cout<<arr[i]<<" ";
         //cout<<"\n";
         for(ll i=0;i+1<n;i++){
            sum=(sum%mod+(a[i]%mod*arr[i+1]%mod)%mod)%mod;
         }
         cout<<sum%mod<<"\n";
    }
}
