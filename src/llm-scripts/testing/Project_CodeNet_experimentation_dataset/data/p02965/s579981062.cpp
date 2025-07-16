#include <bits/stdc++.h>
using i64 = long long;

long long *fact, *inv;

template <typename T, typename U, typename V>
auto pow(T x_, U n_, V mod_) {
    using R = std::common_type_t<T, U, V>;
    R ret = 1, x = x_, n = n_, mod = mod_;
    while(n > 0) {
        if ((n & 1) == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

template <typename T, typename U>
auto inverse(T x, U p) { return pow(x, p - 2, p); }

void init_factorial(int n, long long mod) {
    fact = new long long[n + 1];
    inv = new long long[n + 1];
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    inv[n] = inverse(fact[n], mod);
    for (long long i = n; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
}

int main() {
    constexpr i64 mod = 998244353;
    int n, m;
    std::cin >> n >> m;
    init_factorial(n + 3 * m, mod);

    i64 ret = 0;
    for (int i = 0; i <= std::min(n, m); i++) {
        int r = 3 * m - i;
        if (r & 1) continue;
        r >>= 1;
        i64 t = fact[r + n - 1] * inv[n - 1] % mod * inv[r] % mod;
        ret = (ret + t * fact[n] % mod * inv[i] % mod * inv[n - i] % mod) % mod;
    }

    for (int i = 0; i <= std::min(n, m); i++) {
        int r = m - i;
        if (r & 1) continue;
        r >>= 1;
        i64 t = fact[r + n - 1] * inv[n - 1] % mod * inv[r] % mod;
        ret = (ret + mod - t * fact[n] % mod * inv[i] % mod * inv[n - i] % mod * n % mod) % mod;
    }

    for (int i = 0; i <= std::min(n - 1, m); i++) {
        int r = m - i;
        if (r & 1) continue;
        r >>= 1;
        i64 t = fact[r + n - 2] * inv[n - 2] % mod * inv[r] % mod;
        ret = (ret + t * fact[n - 1] % mod * inv[i] % mod * inv[n - i - 1] % mod * n % mod) % mod;
    }

    std::cout << ret << std::endl;

    return 0;
}
