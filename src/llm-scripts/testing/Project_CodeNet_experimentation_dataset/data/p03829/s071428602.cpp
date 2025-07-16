#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pb  push_back
#define  F   first
#define  S   second
const int N=1e5+5;
ll a[N];
int main()
{
    ft
    ll t,i,j,n,m,l,r,p,q,s=0;
    cin>>n>>l>>r;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        p=(a[i]-a[i-1])*l;
        s+=min(p,r);
    }
    cout<<s<<"\n";
    return 0;
}

