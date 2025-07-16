
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
#define rep2(i, startValue, N) for (int i = (int)(startValue); i < (int)(N); ++i)
// syntax sugar: `for (int i = 0; i < N; ++i)`
#define REP(type, name, beginValue, endCondValue) \
  for (type name = beginValue; name < endCondValue; ++name)
// syntax sugar: 多次元vector
#define VECTOR_DIM3(T, name, d1, d2, d3, initValue) \
    std::vector<std::vector<std::vector<T>>> name(d1, std::vector<std::vector<T>>(d2, std::vector<int>(d3, initValue)));
#define VECTOR_DIM2(T, name, d1, d2, initValue) \
    std::vector<std::vector<T>> name(d1, std::vector<T>(d2, initValue));
#define VECTOR_DIM1(T, name, d1, initValue) \
    std::vector<T> name(d1, initValue);
#define ll long long
#define ld long double

// ABC085C - Otoshidama
int main(){
  int n, y; // 1 <= n <= 2000
  cin >> n >> y;

  for (int a = 0; a <= n; ++a) {
    const int total = a * 10000;
    if (y < total) {
      break;
    }
    for (int b = 0; b <= n-a; ++b) {
      const int total2 = total + b * 5000;
      if (y < total2) {
        break;
      }
      const int c = (n-a-b);
      if (total2 + c * 1000 == y) {
        cout << a << " " << b << " " << c << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}
