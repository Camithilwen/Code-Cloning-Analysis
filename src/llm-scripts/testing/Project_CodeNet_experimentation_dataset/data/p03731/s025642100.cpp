#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N, T;
  cin >> N >> T;

  vector<int> t(N);
  rep(i, N) {
    cin >> t[i];
  }

  long long sum = 0;
  rep(i, N-1) {
    sum += std::min(T, t[i+1] - t[i]);
  }
  sum += T;

  cout << sum << endl;

  return 0;
}
