#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(const T& value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  std::cerr << value << ", ";
  debug(args...);
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
#define in(type, ...) \
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
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

template <typename T>
class BIT {
 public:
  BIT(int n) : v_(n) {}
  T Sum(int i) const {
    T ret = 0;
    while (i >= 0) {
      ret += v_[i];
      i = (i & (i + 1)) - 1;
    }
    return ret;
  }
  T Get(int i) const { return Sum(i) - Sum(i - 1); }
  void Add(int i, T v) {
    while (i < v_.size()) {
      v_[i] += v;
      i |= i + 1;
    }
  }

 private:
  std::vector<T> v_;
};

using P = pair<int, int>;

struct Query {
  int i, l, r;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  in(int, N, M, Q);

  V<P> trains;
  rep(i, M) {
    in(int, L, R);
    trains.push_back({L - 1, R - 1});
  }
  sort(all(trains), [](const P& a, const P& b) { return a.second < b.second; });

  V<Query> queries;
  rep(i, Q) {
    in(int, p, q);
    queries.push_back({i, p - 1, q - 1});
  }
  sort(all(queries), [](const Query& a, const Query& b) { return a.r < b.r; });

  V<int> ans(Q);
  BIT<int> bit(N);
  auto ti = trains.begin();
  auto qi = queries.begin();
  rep(r, N) {
    for (; ti != trains.end() && ti->second <= r; ++ti) {
      bit.Add(ti->first, 1);
    }
    for (; qi != queries.end() && qi->r <= r; ++qi) {
      ans[qi->i] = bit.Sum(qi->r) - bit.Sum(qi->l - 1);
    }
  }
  rep(i, Q) out(ans[i]);
}
