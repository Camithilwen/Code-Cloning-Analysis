#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
#define i(x) cin>>x
#define fr(n,x) for(ll n=0;n<x;n++)
#define pf(x) cout<<x
const ll mod=1e9+7 ;


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    ll x,y;
    cin>>x>>y;
    if (y-x>=2019)
    {
        cout<<0;
        return 0;
    }
    ll res=INT_MAX;
    for(ll n=x;n<=y;n++)
    {
        for(ll k=n+1;k<=y;k++)
        {
            res=min(res,((n%2019)*(k%2019))%2019);
        }
    }
    cout<<res;
}