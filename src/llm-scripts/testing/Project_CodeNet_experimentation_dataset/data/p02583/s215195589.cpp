#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L.at(i);
    }
    int ans = 0;
    FOR(i, 0, N - 2) {
        FOR(j, i + 1, N - 1) {
            FOR(k, j + 1, N) {
                int Li = L.at(i);
                int Lj = L.at(j);
                int Lk = L.at(k);
                if ((Li != Lj) & (Li != Lk) & (Lj != Lk) & (Li + Lj > Lk) &
                    (Lj + Lk > Li) & (Lk + Li > Lj)) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}
