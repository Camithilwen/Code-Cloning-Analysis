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
  in(int, N, M, Q);
  vector<int> l(N + 2), r(N + 2);
  vector<vector<int>> train(N + 1);
  while (M--) {
    in(int, L, R);
    ++l[L];
    ++r[R];
    train[L].push_back(R);
  }
  vector<int> ls(N + 2), rs(N + 2);
  rep(i, N) {
    ls[i + 1] = ls[i] + l[i + 1];
    rs[i + 1] = rs[i] + r[i + 1];
    // rs[N - i] = rs[N - i + 1] + r[N - i];
  }

  vector outside(N + 1, vector(N + 1, 0));
  priority_queue<int> que;
  for (int i = 1; i <= N; ++i) {
    for (int t : train[i - 1]) {
      que.push(-t);
    }
    while (!que.empty() && -que.top() <= i) {
      que.pop();
    }
    priority_queue<int> que2 = que;
    for (int j = i; j <= N; ++j) {
      while (!que2.empty() && -que2.top() <= j) {
        que2.pop();
      }
      outside[i][j] = que2.size();
    }
  }
  while (Q--) {
    in(int, p, q);
    out(rs[q] - ls[p - 1] + outside[p][q]);
    // out(M - (ls[p - 1] + rs[q + 1]));
  }
}