
#include <bits/stdc++.h>

template <typename InputIterator>
typename InputIterator::value_type summation(InputIterator first,
                                             InputIterator last) {
  using T = typename InputIterator::value_type;
  T *p = new T();
  const auto sum = std::accumulate(first, last, *p);
  delete p;
  return sum;
}
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &v);
template <typename T1, typename T2>
std::istream &operator>>(std::istream &stream, std::pair<T1, T2> &p);
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &v) {
  for (auto &i : v) {
    stream >> i;
  }
  return stream;
}
template <typename T1, typename T2>
std::istream &operator>>(std::istream &stream, std::pair<T1, T2> &p) {
  stream >> p.first >> p.second;
  return stream;
}

int main() {
  int64_t n, x;
  std::cin >> n >> x;
  std::vector<int64_t> s(n);
  std::cin >> s;
  std::sort(s.begin(), s.end(), std::greater<int64_t>());

  constexpr int64_t mod = 1000000007;

  std::vector<int64_t> t1(100001, 0), t2(100001, 0);

  t1[x] = 1;

  for (int64_t i = 0; i < n; i++) {
    std::fill(t2.begin(), t2.end(), 0);
    for (int64_t j = 0; j < 100001; j++) {
      t2[j % s[i]] += t1[j] % mod;
      t2[j % s[i]] %= mod;
      t2[j] += t1[j] * (n - i - 1);
      t2[j] %= mod;
    }
    std::swap(t1, t2);
  }

  int64_t ans = 0;

  for (int64_t j = 0; j < 100001; j++) {
    ans += j * t1[j] % mod;
    ans %= mod;
  }

  std::cout << ans << std::endl;

  return 0;
}