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

int main() {
  in(ll, n);
  vector<ll> transportation(5);
  rep(i, 5) cin >> transportation[i];
  vector<ll> population(6);
  population[0] = n;
  ll ans = 0;
  ll last_change = 0;
  while (population[5] < n) {
    ++ans;
    vector<ll> change(6);
    rep(i, 5) {
      ll c = min(transportation[i], population[i]);
      change[i] -= c;
      change[i + 1] += c;
    }
    rep(i, 6) population[i] += change[i];
    if (last_change > 0 && change[5] == last_change) {
      out(ans + (n - population[5] + last_change - 1) / last_change);
      return 0;
    }
    last_change = change[5];
  }
  out(ans);
}
