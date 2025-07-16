//#define NDEBUG
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

namespace n91 {

using i8 = std::int_fast8_t;
using i32 = std::int_fast32_t;
using i64 = std::int_fast64_t;
using u8 = std::uint_fast8_t;
using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;

struct rep {
  struct itr {
    usize i;
    constexpr itr(const usize i) noexcept : i(i) {}
    void operator++() noexcept { ++i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  const itr f, l;
  constexpr rep(const usize f, const usize l) noexcept
      : f(std::min(f, l)), l(l) {}
  constexpr auto begin() const noexcept { return f; }
  constexpr auto end() const noexcept { return l; }
};
struct revrep {
  struct itr {
    usize i;
    constexpr itr(const usize i) noexcept : i(i) {}
    void operator++() noexcept { --i; }
    constexpr usize operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
  };
  const itr f, l;
  constexpr revrep(const usize f, const usize l) noexcept
      : f(l - 1), l(std::min(f, l) - 1) {}
  constexpr auto begin() const noexcept { return f; }
  constexpr auto end() const noexcept { return l; }
};
template <class T> auto md_vec(const usize n, const T &value) {
  return std::vector<T>(n, value);
}
template <class... Args> auto md_vec(const usize n, Args... args) {
  return std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
}
template <class T> constexpr T difference(const T &a, const T &b) noexcept {
  return a < b ? b - a : a - b;
}
template <class T> void chmin(T &a, const T &b) noexcept {
  if (b < a)
    a = b;
}
template <class T> void chmax(T &a, const T &b) noexcept {
  if (a < b)
    a = b;
}
template <class F> class rec_lambda {
  F f;

public:
  rec_lambda(F &&f) : f(std::move(f)) {}
  template <class... Args> auto operator()(Args &&... args) const {
    return f(*this, std::forward<Args>(args)...);
  }
};
template <class F> auto make_rec(F &&f) { return rec_lambda<F>(std::move(f)); }
template <class T> T scan() {
  T ret;
  std::cin >> ret;
  return ret;
}

} // namespace n91

namespace n91 {

void main_() {
  /*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/
  const usize n = scan<usize>();
  const u64 m = scan<u64>();
  const auto add = [&](u64 &l, const u64 r) { l = (l + r) % m; };
  auto dp = md_vec(3 * n + 1 + 3, n + 1 + 1, u64(0));
  dp[0][0] = 1;
  for (const usize i : rep(0, 3 * n + 1)) {
    for (const usize j : rep(0, n + 1)) {
      add(dp[i + 1][j], dp[i][j]);
      add(dp[i + 2][j + 1], dp[i][j] * (i + 1) % m);
      add(dp[i + 3][j + 1], dp[i][j] * (i + 1) % m * (i + 2) % m);
    }
  }
  u64 ans = 0;
  for (const usize i : rep(0, n + 1)) {
    add(ans, dp[3 * n][i]);
  }
  std::cout << ans << std::endl;
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}
