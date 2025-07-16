
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

template<int MOD=P>
struct Mod {
public:
    long long signed value;

    Mod(long long signed val): value(val % MOD) {
        if (value < 0) value += MOD;
    }

    constexpr Mod& operator+=(const Mod& other) noexcept { 
        value += other.value;
        value %= MOD;
        return *this;
    }
    constexpr Mod& operator-=(const Mod& other) noexcept {
        value -= other.value;
        if (value < 0) value += MOD;
        return *this;
    }
    constexpr Mod& operator*=(const Mod& other) noexcept {
        value *= other.value;
        value %= MOD;
        return *this;
    }

    constexpr Mod operator-() noexcept {
         return value == 0 ? 0 : MOD - value;
    }

    constexpr Mod operator+(const Mod& other) const noexcept { return Mod(*this) += other; }
    constexpr Mod operator-(const Mod& other) const noexcept { return Mod(*this) -= other; }
    constexpr Mod operator*(const Mod& other) const noexcept { return Mod(*this) *= other; }
    constexpr bool operator==(const Mod& other) const noexcept { return this->value == other.value; }
    constexpr bool operator!=(const Mod& other) const noexcept { return this->value != other.value; }
};

signed main() {
    capi(n);

    int d[61][2] = {0};

    rep(i, n) {
        capi(a);
        rep(j, 61) {
            ++d[j][a & 1];
            a >>= 1;
        }
    }

    Mod ans(0);

    rep(j, 61) {
        Mod x(1ll << j);
        x *= d[j][0] * d[j][1];
        ans += x;
    }

    cout << ans.value;

    return 0;
}
