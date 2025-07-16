#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr double pi = asin(1) * 2;
constexpr ll mod = 1000000007;

pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0)return make_pair(a, 0);
    auto t = extgcd(b, a % b);
    return make_pair(t.second, t.first - t.second * (a / b));
}

ll invmod(ll n) {
    return extgcd(n, mod).first;
}

class modint {
public:
    ll n;

    modint() = default;

    explicit modint(ll number) {
        n = ((number % mod) + mod) % mod;
    }

    bool operator==(modint e) {
        return n == e.n;
    }

    modint operator+(modint e) {
        return modint(n + e.n);
    }

    modint operator-(modint e) {
        return modint(n - e.n);
    }

    modint operator-(ll e) {
        return modint(n - e);
    }

    modint operator*(modint e) {
        return modint(n * e.n);
    }

    modint operator/(modint e) {
        return modint(n * invmod(e.n));
    }

};

template<class T>
T f1(T n, T m) {
    return m * m * (n * n * (n + T(1)) - (n * (n + T(1)) * (T(2) * n + T(1))) / T(3));
}

template<class T>
T f2(T n, T m) {
    return (f1(n, m) + f1(m, n)) / T(2);
}

template<class T>
T comb(T n, T k) {
    return k == T(0) ? T(1) : comb(n - T(1), k - T(1)) * n / k;
}

int main() {
    modint n, m, k;
    cin >> n.n >> m.n >> k.n;
    cout << (f2(n, m) * comb(n * m - 2, k - 2)).n << endl;
}
