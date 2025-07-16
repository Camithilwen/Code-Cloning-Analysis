#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll mod = 2019;

int main() {
    ll l, r;
    cin >> l >> r;
    map<ll, ll> m;
    for (ll i = l; i <= r && i <= l+5000; i++){
        m[i%mod]++;
    }
    ll ans = 2020;
    vector<ll> a;
    for (auto x: m){
        rep1(i, x.second) a.push_back(x.first);
    }
    ll n = a.size();
    for (ll i=0; i<(n); i++){
        for (ll j=i+1; j<(n); j++){
            ans = min(ans, a[i]*a[j]%2019);
        }
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}