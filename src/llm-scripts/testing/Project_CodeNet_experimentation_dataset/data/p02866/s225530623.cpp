#include <iostream>
#include <map>
#include <cmath>

using namespace std;

#define L 998244353

int main(int argc, char* argv[]) {
  long long N;
  cin >> N;

  long long d[N];
  for (int i = 0; i < N; ++i)
    cin >> d[i];

  if (d[0] != 0) {
    cout << "0" << endl;
    return 0;
  }


  map<long long, long long> m;
  long long max_v = 0;
  for (int i = 0; i < N; ++i) {
    if (m.find(d[i]) == m.end())
      m[d[i]] = 0;
    ++m[d[i]];
    max_v = max(d[i], max_v);
  }

  if (m[0] > 1) {
    cout << 0 << endl;
    return 0;
  }

  long long ret = 1;
  for (long long i = 1; i <= max_v; ++i) {
    if (m.find(i) == m.end()) {
      cout << 0 << endl;
      return 0;
    }
    for (int j = 0; j < m[i]; ++j) {
      ret *= m[i - 1];
      ret %= 998244353;
    }
  }

  cout << ret << endl;

  return 0;
}