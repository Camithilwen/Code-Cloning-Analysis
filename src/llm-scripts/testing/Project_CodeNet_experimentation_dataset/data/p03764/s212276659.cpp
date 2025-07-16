#include<bits/stdc++.h>
using namespace std;
#define pi acos(0.0)
#define ll long long
#define f first
#define s second
#define gap ' '
#define pb push_back
#define mod 1000000007
int main()
{
    ll n,m;
    cin>>n>>m;
    ll x[n+5],y[m+5];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>y[i];
    }
    sort(x,x+n);
    sort(y,y+m);
    ll xx=0;
    ll yy=0;
    for(int i=0;i<n;i++)
    {
        xx+=(i-(n-1))*x[i]+i*x[i];
        //cout<<xx<<endl;
    }

    for(int i=0;i<m;i++)
    {
        yy+=(i-(m-1))*y[i]+i*y[i];
    }

    ll ans=((xx%mod)*(yy%mod))%mod;
    cout<<ans;

}
