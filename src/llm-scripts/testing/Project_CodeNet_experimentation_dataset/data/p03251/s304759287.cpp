//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debugg cout<<"debugged\n";
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
ll n,m,x,y,ans;
void solve()
{
    cin>>n>>m>>x>>y;vector<ll> ar(n),arr(m);
    for(int i=0;i<n;i++)
        cin>>ar[i];
    sort(ar.begin(),ar.end());
    for(int i=0;i<m;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    bool flag=0;
    if(x>ar[n-1]||y<arr[0])
        {cout<<"War"<<endl;return;}
    for(int i=x;i<=y;i++)
    {
        if(i>ar[n-1]&&i<=arr[0])
            {flag=1;break;}
    }
    if(flag)
        cout<<"No War"<<endl;
    else
        cout<<"War"<<endl;
}
void solve2()
{
    cin>>n;ans=0;map<ll,ll>mp;
    for(int i=0;i<n;i++)
    {
        ll a;cin>>a;mp[a]++;
    }
    for(auto it:mp)
    {
       ans=max(ans,it.second);
        
    }
    cout<<ans<<endl;
}
int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}
