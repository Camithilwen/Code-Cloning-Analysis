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
constexpr char eoln = '\n';

} // namespace n91

#include <cassert>

namespace n91 {

void main_() {
  /*
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  //*/
  constexpr usize Inf = std::numeric_limits<usize>::max() / 2;
  const usize n = scan<usize>();
  const usize m = scan<usize>();
  auto g = md_vec(n, n, Inf);
  for (const usize i : rep(0, m)) {
    const usize a = scan<usize>() - 1;
    const usize b = scan<usize>() - 1;
    g[a][b] = 1;
  }
  for (const usize i : rep(0, n)) {
    for (const usize j : rep(0, n)) {
      for (const usize k : rep(0, n)) {
        chmin(g[j][k], g[j][i] + g[i][k]);
      }
    }
  }
  usize st = 0;
  for (const usize i : rep(0, n)) {
    if (g[i][i] < g[st][st]) {
      st = i;
    }
  }
  if (g[st][st] >= Inf) {
    std::cout << "-1" << eoln;
    return;
  }
  std::vector<usize> ans;
  usize v = st;
  do {
    for (const usize i : rep(0, n)) {
      if (g[v][i] == 1 && ans.size() + 1 + g[i][st] == g[st][st]) {
        ans.push_back(i);
        v = i;
        break;
      }
    }
  } while (ans.size() != g[st][st] - 1);
  ans.push_back(st);
  std::cout << ans.size() << eoln;
  for (const auto e : ans) {
    std::cout << e + 1 << eoln;
  }
}

} // namespace n91

int main() {
  n91::main_();
  return 0;
}
