#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M); unordered_map<int, int> a, b; bool ok = true;
    REP(i, 0, N) {
        cin >> A[i];
        if(a[A[i]]) ok = false;
        a[A[i]] = i + 1;
    }
    REP(i, 0, M) {
        cin >> B[i];
        if(b[B[i]]) ok = false;
        b[B[i]] = i + 1;
    }
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }

    int count[N * M + 1] = {};
    REP(i, 0, N) {
        REP(j, 0, M) {
            count[min(A[i], B[j])]++;
        }
    }

    vector<int> acnt(N, 0), bcnt(M, 0);
    REP(i, 0, N) {
        REP(j, 0, M) {
            if (A[i] <= B[j]) acnt[i]++;
        }
    }
    REP(j, 0, M) {
        REP(i, 0, N) {
            if (A[i] >= B[j]) bcnt[j]++;
        }
    }

    ll ans = 1; int cnt = 0;
    for (int i = N * M; i > 0; i--) {
        cnt += count[i];
        if (a[i] && b[i]) {
            continue;
        } else if (a[i]) {
            ans = (ans * acnt[a[i] - 1]) % MOD;
        } else if (b[i]) {
            ans = (ans * bcnt[b[i] - 1]) % MOD;
        } else {
            ans = (ans * (cnt - (N * M - i))) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}