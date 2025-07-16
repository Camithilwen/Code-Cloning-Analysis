#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    ll d, g; cin >> d >> g;
    vector<ll> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];
    ll ans = INF;
    rep(i, (1<<d)) {
        ll sum = 0;
        ll cnt = 0;
        rep(j, d) {
            if(i&(1<<j)) {
                sum += 100 * (j + 1) * p[j] + c[j];
                cnt += p[j];
            }
        }
        //cout << d << ' ' << g << ' ' << ans << ' ' << sum << endl;
        if(sum >= g) {chmin(ans, cnt); continue;}
        for(ll j=d-1; j>=0; j--) {
            if(!(i&(1<<j))) {
                Rep(k, 1, p[j]) {
                    sum += 100 * (j + 1);
                    cnt++;
                    if(sum >= g) chmin(ans, cnt);
                }
            }
        }
    }
    cout << ans << endl;
}
