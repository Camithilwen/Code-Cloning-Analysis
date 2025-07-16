#include <bits/stdc++.h>

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

using namespace std;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int main() {
  rd(int, h, w);
  V<string> s(h);
  rep(r, h) cin >> s[r];
  VV<bool> b(h + 2, V<bool>(w + 2));
  rep(r, h) rep(c, w) b[r + 1][c + 1] = s[r][c] == '#';
  rep(r, h) rep(c, w) if (b[r + 1][c + 1]) {
    bool ok = false;
    rep(i, 4) if (b[r + 1 + dr[i]][c + 1 + dc[i]]) ok = true;
    if (!ok) {
      wt("No");
      return 0;
    }
  }
  wt("Yes");
}
