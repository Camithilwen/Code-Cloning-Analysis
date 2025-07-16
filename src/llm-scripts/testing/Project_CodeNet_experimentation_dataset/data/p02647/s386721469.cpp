#include <bits/stdc++.h>

#if DEBUG
template <typename Iter>
void debug_iter(Iter begin, Iter end);
template <typename T>
void debug(const T& value) {
  std::cerr << value;
}
template <typename T, size_t N>
void debug(const std::array<T, N>& a) {
  debug_iter(a.begin(), a.end());
}
template <typename T>
void debug(const std::vector<T>& v) {
  debug_iter(v.begin(), v.end());
}
template <typename T>
void debug(const std::set<T>& s) {
  debug_iter(s.begin(), s.end());
}
template <typename T, typename U>
void debug(const std::map<T, U>& m) {
  debug_iter(m.begin(), m.end());
}
template <typename T, typename U>
void debug(const std::pair<T, U>& p) {
  std::cerr << "{";
  debug(p.first);
  std::cerr << ", ";
  debug(p.second);
  std::cerr << "}";
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  debug(value);
  std::cerr << ", ";
  debug(args...);
}
template <typename Iter>
void debug_iter(Iter begin, Iter end) {
  std::cerr << "{";
  for (Iter it = begin; it != end; ++it) {
    if (it != begin) std::cerr << ", ";
    debug(*it);
  }
  std::cerr << "}";
}
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define rd(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << '\n';
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define wt(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (T& vi : v) is >> vi;
  return is;
}

template <typename T>
bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

#include <boost/hana/functional/fix.hpp>
auto Fix = [](auto&& f) { return boost::hana::fix(f); };

using ll = long long;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

int main() {
  rd(ll, n, k);
  vector<ll> a(n);
  cin >> a;
  rep(i, k) {
    vector<ll> na(n);
    rep(j, n) na[j] = 1;
    {
      low_priority_queue<ll> que;
      rep(j, n) {
        while (!que.empty() && que.top() < j) que.pop();
        na[j] += que.size();
        que.push(j + a[j]);
      }
    }
    {
      priority_queue<ll> que;
      for (ll j = n - 1; j >= 0; --j) {
        while (!que.empty() && que.top() > j) que.pop();
        na[j] += que.size();
        que.push(j - a[j]);
      }
    }
    if (na == a) break;
    swap(a, na);
  }
  rep(i, n) cout << a[i] << " ";
  cout << endl;
}
