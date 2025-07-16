#include <iostream>
#include <string>

using namespace std;

int const NMAX = 100;
char v[1 + NMAX][1 + NMAX];

int main() {

  int n, m;
  cin >> n >> m;
  cout << max(n * m, max(n - m, n + m));
  return 0;
}
