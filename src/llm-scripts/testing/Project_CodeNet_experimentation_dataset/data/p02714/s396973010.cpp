#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  100005

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    ll ans=0;
    ll r=0,g=0,b=0;
    for(auto u:s)
    {
        if(u=='R')
            r++;
        else if(u=='G')
            g++;
        else
            b++;
    }
    ans=r*g*b;
    // cout<<ans<<endl;
    ll res=0;
    for(int l=1;l<=(n-1)/2;l++)
    {
        for(int i=0;i<n-2*l;i++)
        {
            if(s[i]!=s[i+l]&&s[i]!=s[i+2*l]&&s[i+l]!=s[i+2*l])
            {
                res++;
            }
        }
    }
    cout<<ans-res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}