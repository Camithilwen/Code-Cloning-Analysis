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
#define reprev(i, n) for(int i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

struct UnionFind {
    vector< int > data;
    UnionFind(int sz) {
        data.assign(sz, -1);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }
    int find(int k) {
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }
    int size(int k) {
        return (-data[find(k)]);
    }
};

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    UnionFind uf(2 * n);
    rep (i, m) {
        int a, b; cin >> a >> b; a--; b--;
        uf.unite(2 * a, 2 * b + 1);
        uf.unite(2 * b, 2 * a + 1);
    }
    if (uf.find(0) != uf.find(1)) {
        ll x[2] = {};
        rep (i, n) x[(uf.find(2 * i) != uf.find(0))]++;
        eprintf("%lld %lld\n", x[0], x[1]);
        cout << x[0] * x[1] - m << "\n";
    } else {
        cout << n * (n - 1) / 2 - m << "\n";
    }
    return 0;
}