#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    bool sw[4][100001] = {}; // s:true w:false
    rep (i, 4) rep (j, 2) sw[i][j] = !!(i & (1 << j));
    rep (i, 4) {
        rep (j, n - 2) sw[i][j + 2] = sw[i][j] ^ sw[i][j + 1] ^ (s[(j + 1) % n] == 'o');
        if (sw[i][n - 2] ^ sw[i][n - 1] ^ (s[n - 1] == 'o') == sw[i][0]
            && sw[i][n - 1] ^ sw[i][0] ^ (s[0] == 'o') == sw[i][1]) {
                rep (k, n) cout << (sw[i][k] ? 'S' : 'W');
                cout << "\n";
                return 0;
        }
    }
    cout << "-1\n";
    return 0;
}