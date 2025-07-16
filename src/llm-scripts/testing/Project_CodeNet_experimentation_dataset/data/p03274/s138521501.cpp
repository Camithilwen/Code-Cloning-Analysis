#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    FASTINOUT;
    int x,k;
    cin>>x>>k;
    ll y[x];
    for (int i=0;i<x;i++){
            cin>>y[i];
    }
    ll ans=1e18;
    for (int i=0;i<x-k+1;i++){
        ll l=y[i],r=y[i+k-1];
        if (l<0&&r<0)
            ans=min(ans,-l);
        else if (r>0&&l>0)
            ans=min(ans,r);
        else if (abs(l)>abs(r))
            ans=min(ans,2*abs(r)+abs(l));
        else
            ans=min(ans,abs(r)+2*abs(l));
    }
    cout<<ans;
    return 0;
}
