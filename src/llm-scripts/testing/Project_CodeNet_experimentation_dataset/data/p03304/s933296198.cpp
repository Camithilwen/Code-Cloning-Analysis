#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <stack>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(ll i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右下左上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, -1 };
constexpr int dy[] = { 0, 1, 0, -1, 1, 1 };

namespace {
    template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
    template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

    // 標準出力
    void Write(long long x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Write(const T& x, const char* end = "\n") { std::cout << x << end; }
    template <typename T, typename U> void Write(const T& x, const U& y, const char* end = "\n") { std::cout << x << " " << y << end; }
    template <typename T, typename U, typename V> void Write(const T& x, const U& y, const V& z, const char* end = "\n") { std::cout << x << " " << y << " " << z << end; }
    //template <typename... Args> void Write(Args const&... args) { bool a = true; for (auto const& x : { args... }) { if (a) a = false; else std::cout << " "; std::cout << x; } std::cout << "\n"; }
    template <typename T> void Write(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; ++i) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }
    template <typename T> void Write(const std::vector<std::vector<T>>& x, const char* sep = " ", const char* end = "\n") { for (auto v : x) Write(v, sep, end); }

    // 標準入力
    struct Read {
        std::size_t szi, szj;
        Read(std::size_t _szi = 1, std::size_t _szj = 1) : szi(_szi), szj(_szj) {}
        template <typename T> operator T () const { T a; std::cin >> a; return a; }
        template <typename T> operator std::vector<T>() const { std::vector<T> a(szi); for (std::size_t i = 0; i < szi; ++i) std::cin >> a[i]; return a; }
        template <typename T> operator std::vector<std::vector<T>>() const {
            std::vector<std::vector<T>> a(szi, std::vector<T>(szj));
            for (std::size_t i = 0; i < szi; ++i) for (std::size_t j = 0; j < szj; ++j) cin >> a[i][j]; return a;
        }
        template <typename T, typename U> operator std::vector<std::pair<T, U>>() const {
            std::vector<std::pair<T, U>> a(szi);
            for (std::size_t i = 0; i < szi; ++i) std::cin >> a[i].first >> a[i].second; return a;
        }
    };
    struct Reads {
        template <typename T> Reads(T& a) { std::cin >> a; }
        template <typename T, typename U> Reads(T& a, U& b) { std::cin >> a >> b; }
        template <typename T, typename U, typename V> Reads(T& a, U& b, V& c) { std::cin >> a >> b >> c; }
        template <typename T, typename U, typename V, typename W> Reads(T& a, U& b, V& c, W& d) { std::cin >> a >> b >> c >> d; }
    };

    Read read;
}

int main() {

    int n, m, d; Reads(n, m, d);

    double ans;

    // 隣同士の差がdであるものの個数の平均

    ans = (double)((n - d) * 2) / (n * (double)n) * (m - 1);
    if (d == 0) ans /= 2.0;

    cout << fixed << setprecision(8) << ans << endl;

    return 0;
}
