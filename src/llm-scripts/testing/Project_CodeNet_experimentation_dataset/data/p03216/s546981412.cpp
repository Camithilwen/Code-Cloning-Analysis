#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
ll N, Q;
string S;

ll solve(ll k) {
    ll ret = 0;
    ll D = 0;
    ll M = 0;
    ll C = 0;
    REP(i, N) {
        if (i - k >= 0) {
            ll index = i - k;
            if (S[index] == 'D') {
                D--;
                C -= M;
            }
            else if (S[index] == 'M') {
                M--;
            }
        }

        if (S[i] == 'C')
            ret += C;
        else if (S[i] == 'M') {
            M++;
            C += D;
        }
        else if (S[i] == 'D')
            D++;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> S >> Q;
    REP(i, Q) {
        ll k;
        cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}