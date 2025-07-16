#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll, ll>
#define vl vector<ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    map<ll,ll>m;ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        if(m[a[i]]==0)
        {
            cnt+=1;m[a[i]]+=1;
        }
        else if(m[a[i]]>0)
        {
            cnt-=1;m[a[i]]-=1;
        }
    }
    cout<<cnt<<"\n";
}
