#include <bits/stdc++.h>

using namespace std;

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define INF (1 << 30)
#define LLINF (1LL << 62)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

constexpr int MOD = 1000000007;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template <class T>
string to_string(T s);
template <class S, class T>
string to_string(pair<S, T> p);
string to_string(string s);

template <class T>
string to_string(T v) {
  if (v.empty()) return "{}";
  string ret = "{";
  auto itr = v.begin(), next = ++v.begin();
  for (; next != v.end(); ++itr, ++next) ret += to_string(*itr) + ",";
  ret += to_string(*itr) + "}";
  return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}
string to_string(string s) { return s; }

void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}
void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head) << " ";
  print(tail...);
}

struct IO {
#ifdef _WIN32
  inline char getchar_unlocked() { return getchar(); }
  inline void putchar_unlocked(char c) { putchar(c); }
#endif
  string separator = " ";
  template <class T>
  inline void read(T &x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c != '-' && (c < '0' || '9' < c));
    bool minus = 0;
    if (c == '-') {
      minus = 1;
      c = getchar_unlocked();
    }
    x = 0;
    while ('0' <= c && c <= '9') {
      x *= 10;
      x += c - '0';
      c = getchar_unlocked();
    }
    if (minus) x = -x;
  }
  inline void read(string &x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c == ' ' || c == '\n');
    x.clear();
    do {
      x += c;
      c = getchar_unlocked();
    } while (c != ' ' && c != '\n' && c != EOF);
  }
  template <class T>
  inline void read(vector<T> &v) {
    for (auto &x : v) read(x);
  }
  template <class Head, class... Tail>
  inline void read(Head &head, Tail &... tail) {
    read(head);
    read(tail...);
  }
  template <class T>
  inline void write(T x) {
    char buf[32];
    int p = 0;
    if (x < 0) {
      x = -x;
      putchar_unlocked('-');
    }
    if (x == 0) putchar_unlocked('0');
    while (x > 0) {
      buf[p++] = (x % 10) + '0';
      x /= 10;
    }
    while (p) {
      putchar_unlocked(buf[--p]);
    }
  }
  inline void write(string x) {
    for (char c : x) putchar_unlocked(c);
  }
  inline void write(const char s[]) {
    for (int i = 0; s[i] != 0; ++i) putchar_unlocked(s[i]);
  }
  template <class T>
  inline void write(vector<T> v) {
    for (auto itr = v.begin(); itr + 1 != v.end(); ++itr) {
      write(*itr);
      write(separator);
    }
    write(v.back());
  }
  template <class Head, class... Tail>
  inline void write(Head head, Tail... tail) {
    write(head);
    write(separator);
    write(tail...);
  }
  void set_separator(string s) { separator = s; }
} io;

int main() {
  int N, M;
  io.read(N, M);
  vector<vector<int>> G(N), RG(N);
  REP(i, N + M - 1) {
    int a, b;
    io.read(a, b);
    G[a - 1].push_back(b - 1);
    RG[b - 1].push_back(a - 1);
  }
  int root = -1;
  REP(i, N) if (RG[i].empty()) root = i;
  vector<int> ans(N, -1);
  function<void(int)> dfs = [&](int u) {
    for (auto v : G[u]) {
      if (ans[v] == -1) {
        bool f = 1;
        for (int k : RG[v])
          if (ans[k] == -1 && k != root) f = 0;
        if (f) {
          ans[v] = u;
          dfs(v);
        }
      }
    }
  };
  dfs(root);
  REP(i, N) {
    io.write(ans[i] + 1);
    io.write("\n");
  }
  return 0;
}