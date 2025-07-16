#include <algorithm>
#include <cmath>
#include <cstdio>

#define int long long
#define dotimes(i, n) for (int i : range(n))

using namespace std;

class range {
  class iterator {
    int i, s;
  public:
    iterator(int i, int s): i(i), s(s) {}
    int& operator*() {
      return i;
    }
    void operator++() {
      i += s;
    }
    bool operator!=(iterator const& that) {
      return i < that.i;
    }
  };
  iterator b, e;
public:
  range(int e): b({0, 1}), e({e, 1}) {}
  range(int b, int e): b({b, 1}), e({e, 1}) {}
  range(int b, int e, int s): b({b, s}), e({e, s}) {}
  iterator begin() {
    return b;
  }
  iterator end() {
    return e;
  }
};

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

template<typename T>
inline int size(T container) {
  return static_cast<int>(container.size());
}

template<typename T>
inline bool maxs(T& a, T const& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
inline bool mins(T& a, T const& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  const int k = rint();
  int rf[8] = {}, p[8 - k];
  bool cf[8] = {};
  dotimes(i, k) {
    int r = rint();
    int c = rint();
    rf[r] = c + 1;
    cf[c] = true;
  }
  for (int i = 0, j = 0, c = 0; i < 8; i++)
    if (!rf[i]) {
      while (cf[c])
        c++;
      p[j++] = ++c;
    }
  int a[8];
  for (;; next_permutation(p, p + 8 - k)) {
    for (int i = 0, j = 0; i < 8; i++)
      a[i] = rf[i] ? rf[i] : p[j++];
    dotimes(i, 8)
      dotimes(j, i)
        if (abs(a[j] - a[i]) == abs(j - i))
          goto failed;
    break;
  failed:
    ;
  }
  dotimes(i, 8) {
    dotimes(j, 8)
      putchar(a[i] == j + 1 ? 'Q' : '.');
    putchar('\n');
  }
  return 0;
}

