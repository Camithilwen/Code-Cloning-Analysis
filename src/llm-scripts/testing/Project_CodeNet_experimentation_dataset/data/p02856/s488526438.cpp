#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(ll &m, ll p) {
    ll ret = 1;
    m += p;
    if (m >= 10) {
        ret++;
        m = (m / 10) + (m % 10);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M;
    cin >> M;
    ll ans = 0;
    vector<ll> v(M);
    REP(i, M) {
        ll d, c;
        cin >> d >> c;

        vector<ll> u;
        while (c > 1) {
            if (c % 2 == 1)
                u.push_back(d);
            c /= 2;
            ans += c;
            d = d + d;
            if (d >= 10) {
                d = (d / 10) + (d % 10);
                ans += c;
            }
        }
        u.push_back(d);
        ll n = u[0];
        REP(j, u.size() - 1) {
            ans += calc(n, u[j + 1]);
        }
        v[i] = n;
    }

    ll m = v[0];
    REP(i, M - 1) {
        ans += calc(m, v[i + 1]);
    }
    cout << ans << endl;
    return 0;
}