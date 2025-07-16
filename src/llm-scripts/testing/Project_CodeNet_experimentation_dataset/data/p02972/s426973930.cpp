#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M{};
  cin >> N;
  vector<int> a(N+1), b(N+1);

  for (int i = 1; i <= N; ++i) {
    cin >> a[i];
  }
  for (int i = N; i; --i) {
    int s{};
    for (int j = 2*i; j <=N; j += i) s += b[j];
    if (a[i] != s%2) {
      b[i] = 1;
      ++M;
    }
  }

  cout << M << endl;
  if (!M) return 0;
  for (int i = 1; i <= N; i++) {
    if (!b[i]) continue;
    cout << (M?"":" ") << i;
    M = 0;
  }
  cout << endl;
}
