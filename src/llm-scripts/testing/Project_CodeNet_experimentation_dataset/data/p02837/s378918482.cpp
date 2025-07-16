#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

vector<vector<pair<ll,ll>>> a(15);
vector<ll> l(15, -1);

ll count(ll x, ll n){
    for(auto j : a[x]){
        if(l[j.first-1] != -1 && l[j.first-1] != j.second){
            //cout << "hoge";
            return -1;
        }
        l[j.first-1] = j.second;
    }
    ll ans = 0;
    rep(i, n) if(l[i] == 1) ans++;
    return ans;
}

int main(){
    ll n; cin >> n;
    
    rep(i, n){
        ll b; cin >> b;
        rep(j, b){
            ll x, y; cin >> x >> y;
            a[i].emplace_back(x, y);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < pow(2, n); ++i){
        ll tmp = 0;
        l.assign(15, -1);
        //cout << i << " " << ans << ": ";
        rep(j, n) l[j] = (i & (1 << j)) ? 1 : 0;
        rep(j, n){
            if(!(i & (1 << j))) continue;
            tmp = count(j, n);
            if(tmp == -1) break;
        }
        ans = max(ans, tmp);
        //cout << endl;
        //for(auto x : l) cout << x << " "; cout << endl;
    }
    cout << ans << endl;
    return 0;
}