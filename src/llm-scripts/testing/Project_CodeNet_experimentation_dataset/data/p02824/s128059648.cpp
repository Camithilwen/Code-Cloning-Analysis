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

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
// template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, v, p; cin >> n >> m >> v >> p;
    vector<int> a(n); rep (i, n) cin >> a[i];
    sort(all(a), greater<int>());
    ll ans = 0, piv = a[p - 1];
    if (v <= p) {
        while (ans < n && a[ans] + m >= piv) ans++;
    } else {
        int ok = -1, ng = n;
        while (ng - ok > 1) {
            int med = (ng + ok) / 2;
            if (a[med] + m < piv) {ng = med; continue;}
            ll rest = 0, vv = v - (n - med);
            rep (j, med) rest += max((j < p - 1 ? m : 0LL), (a[med] + m) - a[j]);
            eprintf("%d, %lld %lld\n", med, rest, m * vv);
            if (rest >= m * vv) ok = med;
            else ng = med;
        }
        ans = ok + 1;
    }
    cout << ans << "\n";
    return 0;
}