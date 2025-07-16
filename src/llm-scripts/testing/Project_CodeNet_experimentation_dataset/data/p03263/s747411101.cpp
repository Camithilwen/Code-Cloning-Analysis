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
  in(int, h, w);
  vector a(h, vector(w, 0));
  rep(i, h) rep(j, w) cin >> a[i][j];
  int r = 0, c = 0;
  vector<string> moves;
  while (true) {
    dbg(r, c);
    int nr = r, nc = c + ((r & 1) ? -1 : 1);
    if (nc < 0 || w <= nc) {
      ++nr;
      if (nr == h) break;
      nc = c;
    }
    if (a[r][c] & 1) {
      stringstream ss;
      ss << (r + 1) << " " << (c + 1) << " " << (nr + 1) << " " << (nc + 1);
      moves.push_back(ss.str());
      --a[r][c];
      ++a[nr][nc];
    }
    r = nr;
    c = nc;
  }
  out(moves.size());
  for (auto& m : moves) out(m);
}
