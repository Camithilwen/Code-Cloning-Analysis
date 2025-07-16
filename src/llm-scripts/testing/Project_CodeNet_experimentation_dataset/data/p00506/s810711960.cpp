#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cmath>

using std::begin;
using std::end;

int gcd(int n, int m) {
  if(n < m) return gcd(m, n);
  if(m == 0) return n;

  return gcd(m, n % m);
}

void print_kouyakusu(int n) {
  std::vector<int> v;
  for(int i{1}; i <= std::sqrt(n); ++i) {
    if(n % i == 0) {
      v.push_back(i);
      if(i * i != n) {
        v.push_back(n / i);
      }
    }
  }
  std::sort(begin(v), end(v));
  for(int e: v) {
    std::cout << e << std::endl;
  }
}

int main(int, char**) {
  int n;
  std::cin >> n;
  if(n == 2) {
    int a, b;
    std::cin >> a >> b;

    int d{gcd(a, b)};

    print_kouyakusu(d);
  } else {
    int a, b, c;
    std::cin >> a >> b >> c;

    int d{gcd(a, b)};
    int d2{gcd(c, d)};

    print_kouyakusu(d2);
  }

  return 0;
}

