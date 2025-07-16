#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1005];
ll B[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }
    sort(A, A + N, greater<ll>());
    sort(B, B + M, greater<ll>());

    ll ai = 0, bi = 0;
    ll ans = 1;
    REP(i, N - 1) {
        if (A[i] == A[i + 1])
            ans = 0;
    }
    REP(i, M - 1) {
        if (B[i] == B[i + 1])
            ans = 0;
    }
    if (A[0] != N * M || B[0] != N * M)
        ans = 0;
    for (ll i = N * M; i > 0; --i) {
        if (A[ai + 1] == i)
            ai++;
        if (B[bi + 1] == i)
            bi++;

        ll n = ai + 1;
        ll m = bi + 1;
        if (A[ai] == i)
            n = 1;
        if (B[bi] == i)
            m = 1;

        ll p = n * m;
        if (A[ai] != i && B[bi] != i)
            p -= N * M - i;
        ans = (ans * p) % MOD;
    }

    cout << ans << endl;
    return 0;
}