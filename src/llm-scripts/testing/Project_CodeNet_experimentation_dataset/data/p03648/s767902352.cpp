#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100];
int main()
{
    ll n;
    cin>>n;
    memset(a,0,sizeof(a));
    for(ll i=1;i<=50;i++)
    {
        a[i]=(49+n/50);
    }
    ll m=n%50;
    for(ll i=1;i<=50;i++)
    {
        a[i]=a[i]-m;
    }
    for(ll i=1;i<=m;i++)
    {
        a[i]+=50;
    }
    cout<<50<<endl;
    for(ll i=1;i<=49;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[50]<<endl;
}
