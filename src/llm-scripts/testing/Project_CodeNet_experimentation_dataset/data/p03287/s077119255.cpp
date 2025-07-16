#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    REP(i, 0, N) cin >> A[i];

    int modsum = 0; unordered_map<int, int> m;
    REP(i, 0, N) {
        modsum = (modsum + A[i]) % M;
        m[modsum]++;
    }

    ll ans = 0; modsum = 0;
    REP(i, 0, N) {
        ans += m[modsum];
        modsum = (modsum + A[i]) % M;
        m[modsum]--;
    }
    cout << ans << endl;

    return 0;
}