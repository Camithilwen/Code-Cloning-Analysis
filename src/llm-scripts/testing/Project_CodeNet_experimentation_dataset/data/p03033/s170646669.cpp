#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
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
  std::cout << value << std::endl;
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

using namespace std;

struct Construction {
  ll s, t, x;
  bool operator<(const Construction& c) const { return s < c.s; }
};

struct Person {
  ll d, index;
  bool operator<(const Person& p) const { return d < p.d; }
};

int main() {
  in(ll, n, q);
  vector<Construction> c(n);
  rep(i, n) {
    cin >> c[i].s >> c[i].t >> c[i].x;
    c[i].s -= c[i].x;
    c[i].t -= c[i].x;
  }
  sort(all(c));
  vector<Person> p(q);
  rep(i, q) {
    cin >> p[i].d;
    p[i].index = i;
  }
  sort(all(p));

  multiset<ll> active;
  priority_queue<pair<ll, ll>> que;
  auto cit = c.begin();
  vector<ll> ans(q);
  for (const auto& pi : p) {
    dbg(pi.d, pi.index);
    while (cit != c.end() && cit->s <= pi.d) {
      dbg(cit->s, cit->t, cit->x);
      que.push({-cit->t, cit->x});
      active.insert(cit->x);
      ++cit;
    }
    while (!que.empty() && -que.top().first <= pi.d) {
      dbg(-que.top().first, que.top().second);
      active.erase(active.find(que.top().second));
      que.pop();
    }
    if (active.empty()) {
      ans[pi.index] = -1;
    } else {
      ans[pi.index] = *active.begin();
    }
  }
  rep(i, q) out(ans[i]);
}
