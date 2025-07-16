#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n;
    vector<ll>v;
    cin>>n;
     ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            i++;
            v.push_back(a[i]);
        }
    }
    if(v.size()<2)
        cout<<0<<endl;
    else
    {
        ll x=v.size();
        cout<<(v[x-1]*v[x-2])<<endl;
    }
}
