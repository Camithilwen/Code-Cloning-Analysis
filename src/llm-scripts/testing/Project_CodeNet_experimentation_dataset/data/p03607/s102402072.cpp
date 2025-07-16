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
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    SORT(A);
    int ans   = 0;
    int tmp   = 0;
    int count = 0;
    for (ll& a : A) {
        if (tmp != a) {
            if (count % 2 == 1) { ++ans; }
            count = 0;
        }
        ++count;
        tmp = a;
    }
    if (count % 2 == 1) { ++ans; }
    cout << ans << endl;
}
