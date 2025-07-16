#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int l, r;
    cin >> l >> r;

    if (r - l + 1 >= 2019) {
        cout << 0 << endl;
        return 0;
    }
    ll res = INF;
    for (ll i = l; i < r; ++i) {
        for (ll j = l+1; j <= r; ++j) {
            chmin(res, (i*j) % 2019);
        }
    }
    cout << res << endl;
}
