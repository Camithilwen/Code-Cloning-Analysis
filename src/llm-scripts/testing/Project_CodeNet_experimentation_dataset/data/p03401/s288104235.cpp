#include<bits/stdc++.h>
#define Imposter ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long int
#define ld long double
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define endl "\n"
#define vll vector<ll>
#define vlll vector<vll>
#define all(x) x.begin(),x.end()
int n;
inline void solve()
{
    cin>>n;
    int a[n+2];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    a[0]=0;
    a[n+1]=0;
    ll sum=0;
    for(int i=1;i<n+2;i++)
    {
        sum+=abs(a[i]-a[i-1]);
    }
    //cout<<sum<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<sum-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+ abs(a[i+1]-a[i-1])<<endl;
    }
    
}
int main()
{
    Imposter
    
    int t=1;
    //cin>>t;
    while(t--)
    {
        cout<<fixed<<setprecision(10);
       solve();
        
    }
    return 0;
}