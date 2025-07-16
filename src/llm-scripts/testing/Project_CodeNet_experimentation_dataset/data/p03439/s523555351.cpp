#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

int query(int u) {
    cout << u << endl;
    fflush(stdout);

    string x;
    cin >> x;

    if (x == "Vacant") {
        return 0;
    } else if (x == "Male") {
        return 1;
    } else
        return -1;
}

int main() {
    int N;
    cin >> N;
    int basic = query(0);

    if (basic == 0) return 0;

    int low = 0, high = N;

    while (true) {
        int mid = (low + high) >> 1;
        int col = query(mid);

        if (col == 0) return 0;

        int exp = (mid % 2 == 1 ? -basic : basic);

        if (exp == col) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}