#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

#define int long long
#define ll long long
#define double long double
#define pii pair<int, int>
#define vec vector
#define u_map unordered_map
#define u_set unordered_set
#define str string
#define all(el) el.begin(), el.end()
#define allr(el) el.rbegin(), el.rend()
#define sz(el) (int)el.size()
#define f first
#define s second
#define pb push_back
#define in insert
#define mp make_pair
#define endl "\n"
#define forn(i, n) for (int i = 0; i < n; ++i)

inline int maxi(int &a, int b) { if (b > a) { a = b; return 1; } return 0; }

inline int mini(int &a, int b) { if (b < a) { a = b; return 1; } return 0; }

inline int maxi(double &a, double b) { if (b > a) { a = b; return 1; } return 0; }

inline int mini(double &a, double b) { if (b < a) { a = b; return 1; } return 0; }

int bin_pow(int x, int p) {
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        int ans = bin_pow(x, p / 2);
        return ans * ans;
    }
    return x * bin_pow(x, p - 1);
}

int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

signed main() {

    int n;
    cin >> n;
    multiset<int> hv;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto pos = hv.upper_bound(-x);
        if (pos == hv.end()) {
            ans++;
        } else {
            hv.erase(pos);
        }
        hv.in(-x);
    }
    cout << ans;

    return 0;
}