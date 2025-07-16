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
  if (a < b) {
    return b - a;
  } else {
    return a - b;
  }
}
template <class T> void chmin(T &a, const T &b) noexcept {
  if (b < a) {
    a = b;
  }
}
template <class T> void chmax(T &a, const T &b) noexcept {
  if (a < b) {
    a = b;
  }
}
template <class F> class fix_point : private F {
public:
  explicit constexpr fix_point(F &&f) : F(std::forward<F>(f)) {}

  template <class... Args>
  constexpr decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};
template <class F> constexpr decltype(auto) make_fix(F &&f) {
  return fix_point<F>(std::forward<F>(f));
}
template <class T> T scan() {
  T ret;
  std::cin >> ret;
  return ret;
}

} // namespace n91

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

namespace n91 {

void main_() {
  /*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/
  const usize n = scan<usize>();
  std::vector<u32> x(n);
  for (auto &e : x) {
    std::cin >> e;
  }
  const u32 l = scan<u32>();
  x.push_back(x.back() + l);

  auto dp = md_vec(17, n + 1, usize());
  for (const usize i : rep(0, n)) {
    dp[0][i] = std::distance(
        x.cbegin(),
        std::prev(std::partition_point(
            x.cbegin(), x.cend(), [&](const u32 v) { return v <= x[i] + l; })));
  }
  dp[0][n] = n;
  for (const usize k : rep(1, 17)) {
    for (const usize i : rep(0, n + 1)) {
      dp[k][i] = dp[k - 1][dp[k - 1][i]];
    }
  }

  const usize q = scan<usize>();
  for (const usize i : rep(0, q)) {
    usize a = scan<usize>() - 1;
    usize b = scan<usize>() - 1;
    if (a > b) {
      std::swap(a, b);
    }
    usize ans = 0;
    for (const usize k : revrep(0, 17)) {
      if (dp[k][a] < b) {
        a = dp[k][a];
        ans += static_cast<usize>(1) << k;
      }
    }
    std::cout << ans + 1 << std::endl;
  }
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}
