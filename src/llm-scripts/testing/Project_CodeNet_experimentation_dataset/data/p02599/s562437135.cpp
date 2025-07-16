#include <bits/stdc++.h>

struct FastIO {
  FastIO() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
  }
} fast_io;

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

using ll = long long;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;
#include <math.h>

template <typename T, class DS>
class Mo {
 public:
  Mo(DS& ds) : ds_(ds) {}
  void AddQuery(int begin, int end) {
    int index = queries_.size();
    queries_.push_back({begin, end, index});
  }
  std::vector<T> ProcessQueries() {
    int bin = sqrt(queries_.size());
    sort(queries_.begin(), queries_.end(),
         [&bin](const Query& a, const Query& b) {
           int c = a.begin / bin, d = b.begin / bin;
           if (c != d) return c < d;
           if (c % 2 == 0) {
             return a.end < b.end;
           }
           return a.end > b.end;
         });
    std::vector<T> ret(queries_.size());
    Query p = {0, 0, 0};
    for (std::size_t i = 0; i < queries_.size(); ++i) {
      const Query& c = queries_[i];
      Add(c.begin, p.begin);
      Del(p.begin, c.begin);
      Add(p.end, c.end);
      Del(c.end, p.end);
      ret[c.index] = ds_.Get();
      p = c;
    }
    return ret;
  }

 private:
  struct Query {
    int begin, end, index;
  };
  void Add(int begin, int end) {
    for (int i = begin; i < end; ++i) {
      ds_.Add(i);
    }
  }
  void Del(int begin, int end) {
    for (int i = begin; i < end; ++i) {
      ds_.Del(i);
    }
  }
  DS& ds_;
  std::vector<Query> queries_;
};

using namespace std;

struct DS {
  DS(int n) : c(n), kinds(n), unique_kinds(0) {}
  void Add(int i) {
    if (kinds[c[i] - 1]++ == 0) {
      ++unique_kinds;
    }
  }
  void Del(int i) {
    if (--kinds[c[i] - 1] == 0) {
      --unique_kinds;
    }
  }
  int Get() const { return unique_kinds; }
  V<int> c;
  V<int> kinds;
  int unique_kinds;
};

int main() {
  rd(int, n, q);
  DS ds(n);
  rep(i, n) cin >> ds.c[i];

  Mo<int, DS> mo(ds);
  rep(i, q) {
    rd(int, l, r);
    mo.AddQuery(l - 1, r);
  }

  for (int ans : mo.ProcessQueries()) {
    wt(ans);
  }
}
