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
string to_string(string s) { return s; }
string to_string(const char s[]) { return to_string(string(s)); }

template <class T>
string to_string(T v) {
  if (v.empty()) return "{}";
  string ret = "{";
  for (auto x : v) ret += to_string(x) + ",";
  ret.back() = '}';
  return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

struct IO {
#ifdef _WIN32
  inline char getchar_unlocked() { return getchar(); }
  inline void putchar_unlocked(char c) { putchar(c); }
#endif
  string separator = " ";
  template <class T>
  inline void read(T& x) {
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
  inline void read(string& x) {
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
  inline void read(vector<T>& v) {
    for (auto& x : v) read(x);
  }
  template <class Head, class... Tail>
  inline void read(Head& head, Tail&... tail) {
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
  template <class Head, class... Tail>
  inline void writeln(Head head, Tail... tail) {
    write(head, tail...);
    write("\n");
  }
  void set_separator(string s) { separator = s; }
} io;

int main() {
  int N;
  string S;
  io.read(N, S);
  using Pss = pair<string, string>;
  map<Pss, ll> left, right;
  ll ans = 0;
  REP(b, 1 << N) {
    string l_r, l_b, r_r, r_b;
    REP(i, N)
    if ((b >> i) & 1) {
      l_r += S[i];
      r_r += S[2 * N - 1 - i];
    } else {
      l_b += S[i];
      r_b += S[2 * N - 1 - i];
    }
    left[Pss(l_r, l_b)]++;
    right[Pss(r_r, r_b)]++;
  }
  for (auto l : left)
    ans += l.second * right[Pss(l.first.second, l.first.first)];
  io.writeln(ans);
  return 0;
}