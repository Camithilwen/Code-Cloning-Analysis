#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
template <typename T> using vvec = vector<vector<T>>;

constexpr int64_t mpow(int64_t a, int64_t b, int64_t mod = 1000000007) {
    if (b <= 0) { return 1; } if (b == 1) { return a % mod; } if (b == 2) { return (a * a) % mod; }
    return (max(a * (b & 1), (int64_t)1) * mpow(mpow(a, b / 2, mod), 2, mod)) % mod;
}
constexpr int64_t mdiv(int64_t a, int64_t b, int64_t mod = 1000000007) {
    return (a * mpow(b, mod - 2, mod)) % mod;
}

int main() {
    int n, l; cin >> n >> l;
    int all = n * (n - 1) / 2 + l * n;
    if (0 <= l) {
        cout << all - l << endl;
        return 0;
    }
    if (abs(l) < n) {
        cout << all << endl;
        return 0;
    }
    cout << all - (l + n - 1) << endl;
}

