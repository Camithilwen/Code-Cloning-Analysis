#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll a,b,m,ans;
    cin>>a>>b>>m;
    vector<ll> A(a),B(b);
    rep(i,a) cin>>A[i];
    rep(i,b) cin>>B[i];

    ll minia=*min_element(all(A)),minib=*min_element(all(B));
    ans=minia+minib;
    rep(i,m){
        ll x,y,c;
        cin>>x>>y>>c;
        ans = min(ans, A[x-1]+B[y-1]-c);
    }
    
    cout<<ans<<endl;
    return 0;
}