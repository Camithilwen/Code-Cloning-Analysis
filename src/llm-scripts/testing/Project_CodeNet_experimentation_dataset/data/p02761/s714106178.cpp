#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cstdint>
#include <cmath>
using namespace std;

inline namespace atcoder {
    using i32 = int32_t; using u32 = uint32_t;
    using i64 = int64_t; using u64 = uint64_t;
    using f32 = float; using f64 = double;

    template <typename T, size_t Depth>
    struct vector_helper { using type = vector<typename vector_helper<T, Depth - 1>::type>; };
    template <typename T>
    struct vector_helper<T, 0> { using type = T; };
    template <typename T, size_t Depth>
    using vector_t = typename vector_helper<T, Depth>::type;

    template <typename T> using vec = vector_t<T, 1>;
    template <typename T> using vvec = vector_t<T, 2>;
    template <typename T> using vvvec = vector_t<T, 3>;
}

int main() {
    int n, m; cin >> n >> m;

    int expect[] = { -1, -1, -1 };
    while (m--) {
        int s, c; cin >> s >> c; --s;
        if (expect[s] != -1 && expect[s] != c) {
            cout << -1 << endl;
            return 0;
        }
        expect[s] = c;
    }

    if (n != 1 && expect[0] == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (n != 1 && expect[0] == -1) {
        expect[0] = 1;
    }
    for (auto &e : expect) e = max(e, 0);

    int ans = 0;
    for (int i = n - 1; 0 <= i; --i) {
        ans += expect[i] * pow(10, n - 1 - i);
    }

    cout << ans << endl;
}

