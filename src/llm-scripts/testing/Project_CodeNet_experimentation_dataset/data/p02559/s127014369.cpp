#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    cin >> N >> Q;
    atcoder::fenwick_tree<ll> bit(N);
    REP(i, N) {
        ll a;
        cin >> a;
        bit.add(i, a);
    }

    REP(_, Q) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            bit.add(a, b);
        }
        else {
            cout << bit.sum(a, b) << endl;
        }
    }
    return 0;
}