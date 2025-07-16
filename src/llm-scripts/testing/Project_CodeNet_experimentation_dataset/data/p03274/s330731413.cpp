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

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> x(n); cin >> x;
    ll inf = 1000000000, ans = inf;
    rep(i, n-k+1){
        ll a = x[i], b = x[i+k-1];
        if(a < 0 && b < 0) ans = min(ans, abs(a));
        else if(a > 0 && b > 0) ans = min(ans, b);
        else{
            if(abs(a) < abs(b)) ans = min(ans, abs(a)*2 + abs(b));
            else ans = min(ans, abs(a) + abs(b)*2);
        }
    }
    cout << ans << endl;
    
    return 0;
}