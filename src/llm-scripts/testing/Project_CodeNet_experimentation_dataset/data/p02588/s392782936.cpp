#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll calc(ll x){
    ll res = 1;
    while(x%2 == 0){
        x /= 2;
        res *= 2;
    }
    while(x%5 == 0){
        x /= 5;
        res *= 5;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<P, ll> mp;
    rep(i,n){
        string s;
        cin >> s;
        ll a = 0, b = 1;
        bool f = false;
        for(char c : s){
            if(c == '.'){
                f = true;
                continue;
            }
            a = a * 10 + (c - '0');
            if(f) b *= 10;
        }
        ll g = gcd(a, b);
        a /= g;
        a = calc(a);
        b /= g;
        b = calc(b);
        ++mp[P(a, b)];
    }
    vector<P> v;
    v.reserve(mp.size());
    for(auto& p : mp){
        v.push_back(p.first);
    }
    int sz = v.size();
    ll ans = 0;
    rep(i,sz){
        P p1 = v[i];
        rep(j,i+1){
            P p2 = v[j];
            if(p2.first % p1.second == 0 && p1.first % p2.second == 0){
                ll tmp = mp[p1] * mp[p2];
                if(i == j){
                    tmp -= mp[p1];
                    tmp /= 2;
                }
                ans += tmp;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
