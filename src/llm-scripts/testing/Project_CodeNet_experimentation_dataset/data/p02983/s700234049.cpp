// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double

#define pll pair<ll,ll>
#define ff first
#define ss second

#define pb push_back
#define all(x) x.begin(),x.end()

#define MOD  1000000007
const int N = 100005; 

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

void solve()
{   
    ll l,r;
    cin >> l >> r;
    ll dif = (r - l + 1);
    if(dif>=2020)    
    {
        cout<<"0\n";
    }
    else
    {
        ll ans = 1e18;
        for(ll i=l;i<=r;i++)
        {
            for(ll j=i+1;j<=r;j++)
            {
                ll temp = i*j;
                temp %= 2019;
                ans = min(ans,temp);
            }
        }
        cout<<ans;
    }
}

int main()
{
    FAST;
    int t = 1;
 // cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
} 