#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n)cin >> v[i];

    ll ans = 0;
    rep(left, min(n, k) + 1)rep(right, min(n, k) + 1 - left){
        vector<ll> res = v;
        res.erase(res.begin()+left, res.end()-right);

        sort(ALL(res));

       rep(i, k-left-right){
            if(res.empty() || res.front() >= 0)break;
            res.erase(res.begin());
        }

        ans = max(ans, accumulate(ALL(res), 0LL));
    }

    cout << ans << endl;
}