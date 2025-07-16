#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,m,x,y; cin>>n>>m>>x>>y;
    vector<ll> a(n),b(m);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    sort(all(a));
    sort(all(b));
    bool can=false;
    for(int i=x+1;i<=y;i++){
        if(a[n-1]<i && i<=b[0]) can=true;
        else continue;
    }

    cout<<(can?"No War":"War")<<endl;
    return 0;
}