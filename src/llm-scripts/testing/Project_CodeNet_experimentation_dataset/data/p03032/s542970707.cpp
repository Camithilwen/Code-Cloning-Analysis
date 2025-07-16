#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

vector<vector<ll>> g(100010); 
vector<ll> dist(100010);

int main(){
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    rep(i, n)cin >> v[i];

    ll ans = 0;
    rep(i, min(n, k) + 1)rep(j, min(n, k) + 1 - i){
        vector<ll> tmp = v;
        tmp.erase(tmp.begin()+i, tmp.end()-j);

        sort(ALL(tmp));

        rep(l, k - (i+j) && !tmp.empty()){
            if(tmp.front() < 0)tmp.erase(tmp.begin());
        }

        ll res = 0;
        rep(l, tmp.size())res += tmp[l];

        ans = max(ans, res);
    }

    cout << ans << endl;
}