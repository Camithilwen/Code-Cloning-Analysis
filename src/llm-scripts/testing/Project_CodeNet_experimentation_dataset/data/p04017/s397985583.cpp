#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iterator>
#include <fstream>
#include <math.h>

#include <random>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <list>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

#include <random>
#include <ctime>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define FOR(i, from, to) for (int i = from; i < to; i++)
#define ROF(i, from, to) for (int i = from; i > to; i--)

const long double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int INFS = 1000000000;
const ll M = 1000000007;
const ll LLINF = 1000000000000000000;
const double EPS = 1e-8;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> x(n);
    map<int, int> mp = {};
    FOR(i, 0, n) {
        cin >> x[i];
        mp[x[i]] = i;
    }
    int l;
    cin >> l;
    vector<vector<int> > st(n, vector<int>(21));
    FOR(i, 0, n)
        st[i][0] = mp[*(--upper_bound(x.begin(), x.end(), x[i] + l))];
    FOR(j, 1, 21) {
        FOR(i, 0, n) {
            st[i][j] = st[st[i][j - 1]][j - 1];
            // cout << i << ' ' << j << ' ' << st[i][j] << endl;
        }
    }
    int m, a, b, cr, ans;
    cin >> m;
    while (m--) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        --a; --b;
        ans = 0;
        cr = a;
        ROF(j, 20, -1) {
            if (st[cr][j] < b) {
                cr = st[cr][j];
                ans += (1 << j);
            }
        }
        ++ans;
        cout << ans << "\n";
    }

    return 0;
}
