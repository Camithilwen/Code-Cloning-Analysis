#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, t;
    cin >> n >> t;

    int ans = 0, tnow, tpush, tbfr;
    cin >> tbfr;
    for(int in=1;in<n;in++) {
        cin >> tpush;
        if(tpush-tbfr<=t) ans += tpush-tbfr;
        else ans += t;
        tbfr = tpush;
    }
    ans += t;
    cout << ans << endl;
    return 0;
}
