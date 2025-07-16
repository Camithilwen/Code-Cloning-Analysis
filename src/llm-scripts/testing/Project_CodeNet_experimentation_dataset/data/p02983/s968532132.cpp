#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll l, r, ans=INF;
    cin >> l >> r;
    r = min(r, l+4038);
    for(ll i=l;i<=r;i++)for(ll j=i+1;j<=r;j++){
        ll tmp = ((i%2019)*(j%2019))%2019;
        ans = min(ans, tmp);
        ans %= 2019;
    }
    cout << ans << endl;
    return 0;
}