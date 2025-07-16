#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 50;

ll N;
ll X[100005];
ll D[100005][MAX];

ll solve(ll a, ll b) {
    if (a > b)
        swap(a, b);
    ll ret = 0;
    for (ll x = MAX - 1; x >= 0; --x) {
        ll nxt = D[a][x];
        if (nxt < 0 || nxt > b)
            continue;
        ret |= (1LL << x);
        a = nxt;
    }
    if (a < b)
        ret++;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        cin >> X[i];
    }
    ll L;
    cin >> L;

    memset(D, -1, sizeof(D));
    ll n = 0;
    REP(i, N - 1) {
        while (n < N && X[n + 1] - X[i] <= L)
            n++;
        D[i][0] = n;
    }

    FOR(x, MAX, 1) {
        REP(i, N - 1) {
            if (D[i][x - 1] < 0)
                continue;
            D[i][x] = D[D[i][x - 1]][x - 1];
        }
    }

    ll Q;
    cin >> Q;

    REP(_, Q) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a - 1, b - 1) << endl;
    }
    return 0;
}