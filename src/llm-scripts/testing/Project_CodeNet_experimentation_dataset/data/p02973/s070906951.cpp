#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, a;
    multiset<int> ms;
    cin >> n;
    while (n--) {
        cin >> a;
        auto it = ms.lower_bound(a);
        if (it == ms.begin()) {
            ms.insert(a);
        }
        else {
            ms.erase(--it);
            ms.insert(a);
        }
    }
    cout << ms.size() << endl;

    return 0;
}