#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

ll n, l, q;
ll x[100009], nxt[100009][17];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    rep(i, n) cin >> x[i];
    cin >> l;
    ll y = 0;
    rep(i, n) {
        while(y + 1 < n && x[i] + l >= x[y + 1]) {
            y++;
        }
        nxt[i][0] = y;
    }
    rep(i, 16) rep(j, n) nxt[j][i + 1] = nxt[nxt[j][i]][i];

    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if(b < a) swap(a, b);
        ll ans = 1;
        for(int i = 16; i >= 0; i--) {
            if(nxt[a][i] < b) {
                a = nxt[a][i];
                ans += 1 << i;
            }
        }
        cout << ans << endl;
    }

    return 0;
}