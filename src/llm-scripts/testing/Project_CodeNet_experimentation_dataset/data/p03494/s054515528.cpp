#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count ( ll n)
{
    ll ans =0;
    while( n%2==0)
    {
        n= n/2;
        ans++;
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans = min(ans , count(a[i]));
    }
    cout<<ans;
}