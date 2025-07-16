#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <time.h>
#include <random>
#include <string>
#include <cassert>
#include <vector>
#include <ostream>
#include <istream>
#include <stack>
#include <deque>
#include <queue>
#include <functional>
#include <chrono>
#include <stack>

using namespace std;

#define int long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define ld long double

ostream& operator<< (ostream &out, const vector<int> &b) {
    for (auto k : b) out << k << " ";
    return out;
}

istream& operator>> (istream& in, pii& b) {
    in >> b.first >> b.second;
    return in;
}

ostream& operator<< (ostream& out, const pii& b) {
    out << "{" << b.first << ", " << b.second << "}";
    return out;
}

template <typename T1, typename T2> inline bool chkmin(T1 &x, const T2 &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T1, typename T2> inline bool chkmax(T1 &x, const T2 &y) {if (x < y) {x = y; return 1;} return 0;}


#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << (x) << "\n";
    const int INF = 1e18;
    // const int mod = 2600000069;
    // const int p = 10;
#else
    #define dbg(x) 57
    const int INF = 1e18;
    // const int mod = 2600000069;
    // const int p = 179;
#endif

const ld PI = acos(-1);

#define time clock() / (double) CLOCKS_PER_SEC

// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,sse3,sse4")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC target("avx2")  
// #pragma GCC optimize("section-anchors")
// #pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
// #pragma GCC optimize("vpt")
// #pragma GCC optimize("rename-registers")
// #pragma GCC optimize("move-loop-invariants")
// #pragma GCC optimize("unswitch-loops")
// #pragma GCC optimize("function-sections")
// #pragma GCC optimize("data-sections")

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
 
const int MAXN = 2e5 + 10;
const int K = 20;

int n, l, q;
int a[MAXN], up[MAXN][K];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> l >> q;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        while (ptr < n - 1 && a[ptr + 1] - a[i] <= l) {
            ptr++;
        }
        up[i][0] = ptr;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j < K; j++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        int ans = 0;
        for (int i = K - 1; i >= 0; i--) {
            if (up[x][i] < y) {
                ans += (1 << i);
                x = up[x][i];
            }
        }
        cout << ans + 1 << "\n";
    }
}
/*

*/