#include <cstdint>
#include <cstdio>

#include <atcoder/fenwicktree>

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  atcoder::fenwick_tree<intmax_t> ft(n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ft.add(i, a);
  }

  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);

    if (t == 0) {
      int p, x;
      scanf("%d %d", &p, &x);
      ft.add(p, x);
    } else if (t == 1) {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%jd\n", ft.sum(l, r));
    }
  }
}
