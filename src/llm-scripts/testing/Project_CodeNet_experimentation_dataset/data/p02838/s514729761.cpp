#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; 
using namespace std;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
typedef long long  ll;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef pair<ll,ll> PLL;
typedef pair<int,int> PII;
#define pb push_back

#define F first
#define S second
#define SZ(a) int((a).size())
#define ALL(a) a.begin(),a.end()
#define fr(i,x,y) for(int i=x;i<y;i++)
#define frr(i,x,y) for(int i=x-1;i>=y;i--)
#define inf 1e18+1
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll power(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;}a=a*a;b>>=1;}return ans;}
ll powerm(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;ans%=mod;}a=a*a;a%=mod;b>>=1;}return ans%mod;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

void solve()
{
    ll n;
    cin>>n;
    vector<VL> pref(n+2,VL(60,0));
    VL arr(n);
    fr(i,0,n)
    {
        cin>>arr[i];
        ll x=arr[i];
        fr(j,0,60)
        {
            if(x&(1LL<<j))
            {
                pref[i+1][j]=1;
            }
        }
    }
    fr(j,0,60)
    {
        frr(i,n+1,1)
        {
            pref[i][j]+=pref[i+1][j];
        }
    }
    ll ans=0;

    fr(i,0,n-1)
    {
        //cin>>arr[i];
        ll x=arr[i];
        ll rem=n-(i+1);
        fr(j,0,60)
        {
            if(x&(1LL<<j))
            {
                ans+=(powerm(2,j)*(rem-pref[i+2][j])%mod);
                //scout<<x<<' '<<j<<endl;
            }
            else
            {
                ans+=(powerm(2,j)*(pref[i+2][j])%mod);
            }
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    IOS;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        //cout<<"Case #"<<pp-t<<":\n";
        solve();
    }
    return 0;
}
/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
*/
/*
recursion - matrix exponential

*/
// BITMASK:
// 1)When some constrall is of the order of 15-20, think of bitmask DP.
// 2)When some constrall is around 40, try out meet in the middle
// 3) See Strings,palindromes,prefix,suffix etc -> KMP,Z algorithm