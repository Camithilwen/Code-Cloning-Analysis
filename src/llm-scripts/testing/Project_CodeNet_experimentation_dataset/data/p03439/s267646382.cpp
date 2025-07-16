#include "bits/stdc++.h"
// Begin Header {{{
#define all(x)          (x).begin(), (x).end()
#define rep(i, s, n)    for (i64 i = (s), i##_limit = (n); i < i##_limit; ++i)
#define repr(i, s, t)   for (i64 i = (s), i##_limit = (t); i >= i##_limit; --i)
#define var(type, ...)  type __VA_ARGS__; read(__VA_ARGS__);
#ifndef DBG
#define dump(...)
#endif
using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template <class T, class U> inline bool chmax(T &a, const U &b) { return b > a && (a = b, true); }
template <class T, class U> inline bool chmin(T &a, const U &b) { return b < a && (a = b, true); }
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T>
inline vector<T> makeV(const T &initValue, size_t sz) {
    return vector<T>(sz, initValue);
}

template <class T, class... Args>
inline auto makeV(const T &initValue, size_t sz, Args... args) {
    return vector<decltype(makeV<T>(initValue, args...))>(sz, makeV<T>(initValue, args...));
}

template <class T>
inline istream& operator>> (istream &is, vector<T> &vec) {
    for (auto &e : vec) is >> e;
    return is;
}

inline void read() {}

template <class Head, class... Tail>
inline void read(Head &head, Tail&... tail) { cin >> head; read(tail...); }

inline void print() { cout << "\n"; }

template <class Head, class... Tail>
inline void print(Head &&head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail)) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
inline ostream& operator<< (ostream &os, const vector<T> &vec) {
    static constexpr const char *delim[] = { " ", "" };
    for (const auto &e : vec) os << e << delim[&e == &vec.back()];
    return os;
}

template <class Container>
struct Rev {
    Container &x_;
    inline Rev(Container &x): x_(x) {}
    inline auto begin() { return rbegin(x_); }
    inline auto end() { return rend(x_); }
};
// }}} End Header

signed main() {
    var(int, N);
    string res;

    vector<int> a(N, -1);

    const auto ask = [&](int n) -> int {
        string res;
        cout << n << endl;
        cin >> res;
        if (res == "Vacant") return a[n] = 0;
        if (res == "Male") return a[n] = 1;
        return a[n] = 2;
    };

    if (ask(0) == 0) return 0;
    int begin = 0;
    int end = N;

    int cnt = 0;
    while (++cnt <= 20 && end - begin > 1) {
        const int mid = (begin + end) / 2;
        if (ask(mid) == 0) return 0;

        if ((a[begin] == a[mid]) == ((mid - begin) & 1)) {
            end = mid;
        } else {
            begin = mid;
        }
    }

    return 255;
}
