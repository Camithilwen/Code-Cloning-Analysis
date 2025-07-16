#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOE(x, a) for(auto x : a)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int N = 2e5 + 10;
const ll INF = 1e18;

struct segmentTree{
    ll d[N * 4], lazy[N * 4];
    void doLazy(int id, int l, int r){
        d[id] += lazy[id];
        if (l < r){
            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
        }
        lazy[id] = 0;
    }
    void update(int id, int l, int r, int u, int v, ll val){
        doLazy(id, l, r);
        if (v < l || r < u)
            return;
        if (u <= l && r <= v){
            lazy[id] += val;
            doLazy(id, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        d[id] = min(d[id << 1], d[id << 1 | 1]);
    }
    ll getMin(int id, int l, int r, int u, int v){
        doLazy(id, l, r);
        if (v < l || r < u)
            return INF;
        if (u <= l && r <= v)
            return d[id];
        int mid = (l + r) >> 1;
        return min(getMin(id << 1, l, mid, u, v), getMin(id << 1 | 1, mid + 1, r, u, v));
    }
} ST[2];

int n, q, a, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q >> a >> b;

    FOR(i, 1, n){
        ST[0].update(1, 1, n, i, i, abs(b - i) - i);
        ST[1].update(1, 1, n, i, i, abs(b - i) + i);
    }

    while (q--){
        int x;
        cin >> x;

        ll cur = ST[0].getMin(1, 1, n, a, a) + a;
        ll minVal = min(ST[0].getMin(1, 1, n, 1, x) + x, ST[1].getMin(1, 1, n, x, n) - x);
        minVal = min(minVal, cur + abs(x - a));

        ST[0].update(1, 1, n, a, a, minVal - cur);
        ST[1].update(1, 1, n, a, a, minVal - cur);

        if (a > 1){
            ST[0].update(1, 1, n, 1, a - 1, abs(x - a));
            ST[1].update(1, 1, n, 1, a - 1, abs(x - a));
        }

        if (a < n){
            ST[0].update(1, 1, n, a + 1, n, abs(x - a));
            ST[1].update(1, 1, n, a + 1, n, abs(x - a));
        }
        a = x;
    }

    ll ans = INF;
    FOR(i, 1, n)
        ans = min(ans, ST[0].getMin(1, 1, n, i, i) + i);

    cout << ans;

    return 0;
}
