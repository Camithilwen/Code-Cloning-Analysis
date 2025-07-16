// -*- mode:c++; coding:utf-8; indent-tabs-mode:nil; -*-
// ALDS1_2-D

#include <algorithm>
#include <cstdio>

static void print_ints(const int as[], const unsigned int n,
                       const char* sep = " ") {
  const char* out_sep = "";
  for (unsigned int i = 0; i < n; ++i) {
    std::printf("%s%d", out_sep, as[i]);
    out_sep = sep;
  }
  std::puts("");
}

static void print_int(const unsigned int n) {
  std::printf("%d\n", n);
}

static unsigned int cnt = 0;

inline
static void insert(int as[], const unsigned int i, const unsigned int d) {
  const int asi = as[i];
  unsigned int j = i;
  while (j >= d && asi < as[j-d]) {
    as[j] = as[j-d];
    j -= d;
    ++cnt;
  }
  as[j] = asi;
}

void insertion_sort(int as[], const unsigned int n, const unsigned int d) {
  for (unsigned int i = d; i < n; ++i) {
    insert(as, i, d);
  }
}

inline
unsigned int next_g(const unsigned int g) { return 3*g + 1; }

unsigned int gen_m(const unsigned int n) {
  unsigned int m = 1;
  for (unsigned int g = 1;;) {
    g = next_g(g);
    if (n < g) break;
    ++m;
  }
  return m;
}

void shell_sort(int as[], const unsigned int n) {
  cnt = 0;

  unsigned int m = gen_m(n);
  int gs[m];
  for (unsigned int g = 1, i = 0; i < m; ++i) {
    gs[m-1-i] = g;
    g = next_g(g);
  }
  print_int(m);
  print_ints(gs, m);

  for(unsigned int i = 0; i < m; ++i) {
    insertion_sort(as, n, gs[i]);
  }
  
  print_int(cnt);
}

int main(void) {
  unsigned int n;
  std::scanf("%d", &n);
  int as[n];
  for (unsigned int i = 0; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }

  shell_sort(as, n);
  print_ints(as, n, "\n");

  return 0;
}
// end