#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, m;
    cin >> n >> m;

    map<ll, ll> mp;
    ll ans = 0;
    ll sum = 0;
    rep(i, n){
        ll a;
        cin >> a;
        sum += a;
        if(sum % m == 0)ans++;

        if(mp.count(sum % m) > 0){
            ans += mp[sum % m];
            mp[sum % m]++;
        }
        else {
            mp[sum % m] = 1;
        }
    }

    cout << ans << endl;
}