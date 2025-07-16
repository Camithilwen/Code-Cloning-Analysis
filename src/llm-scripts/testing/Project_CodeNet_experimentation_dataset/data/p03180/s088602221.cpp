//#pragma  GCC optimize("Ofast")

//#ifdef  DEBUG
//#define _GLIBCXX_DEBUG
//#endif

// -Ofast
// -O3
// -O2
// -fsanitize=address
// -fsanitize=undefined

// add_compile_options()

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <random>

using namespace std;
//using namesparsace __gnu_pbds;

void solve();

int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    solve();
    return 0;
}

#define ld double
#define int long long

const int maxN = 3e3 + 10, maxK = 1e5 + 10, inf = 1e15 + 10, mod = 1e9 + 7, base = 223;

int n, a[16][16], cost[1 << 16], dp[1 << 16];

bool bit(int a, int i) {
    return (a >> i) & 1;
}

int get(int mask) {
    vector < int > v;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (bit(mask, i)) {
            for (int j = 0; j < v.size(); j++) {
                res += a[v[j]][i];
            }
            v.push_back(i);
        }
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < (1 << n); i++) {
        cost[i] = get(i);
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        int submask = mask;
        while (submask > 0) {
            dp[mask] = max(dp[mask], dp[mask ^ submask] + cost[submask]);
            submask = mask & (submask - 1);
        }
    }
    cout << dp[(1 << n) - 1];
}

// submask = mask & (mask - 1);