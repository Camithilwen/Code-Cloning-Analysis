#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

bool f(std::vector<intmax_t>& a) {
  std::sort(a.rbegin(), a.rend());
  intmax_t n = a.size();
  a[0] -= n;
  for (size_t i = 1; i < a.size(); ++i) ++a[i];
  std::sort(a.begin(), a.end());

  return !std::all_of(a.begin(), a.end(), [=](auto x) { return x < n; });
}

int main() {
  intmax_t k;
  scanf("%zu", &k);

  size_t n = 50;
  std::vector<intmax_t> a(n, n+(n+k-1)/n);
  for (size_t i = 0; i < 50; ++i) f(a);
  if (k % n != 0) {
    size_t m = n - k%n;
    for (size_t i = 0; i < m; ++i) f(a);
  }

  printf("%zu\n", n);
  for (size_t i = 0; i < a.size(); ++i)
    printf("%jd%c", a[i], i+1<a.size()? ' ': '\n');
}
