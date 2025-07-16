#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,q,m=0;
    cin>>n>>q;
    vector<ll> a(n+1);
    string s;
    cin>>s;
    for(int i=1;i<n;i++)
       {
        if(s[i-1]=='A'&& s[i]=='C')
        {
            a[i]=1;
        }
       }
    for(int i=1;i<=n;i++)
      a[i]+=a[i-1];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(r==l) cout<<0<<endl;
        else
        { r--;
         cout<<a[r]-a[l-1]<<endl;
        }
    }
    return 0;
}
