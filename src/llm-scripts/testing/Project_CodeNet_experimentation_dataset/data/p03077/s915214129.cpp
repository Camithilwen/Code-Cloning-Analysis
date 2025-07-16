#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,a,b,c,d,e;cin>>n>>a>>b>>c>>d>>e;

    ll s=min(min(min(min(a,b),c),d),e);

    ll ans=(n-1)/s+5;

    cout<<ans<<"\n";

    return 0;
}
