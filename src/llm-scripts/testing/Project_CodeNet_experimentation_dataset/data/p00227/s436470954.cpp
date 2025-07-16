#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  long long p[1000];

  while(1) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      ans += p[i];
    }

    sort(p, p+n, std::greater<long long>());

    for (int i = m-1; i < n; i += m) {
      ans -= p[i];
    }

    cout << ans << endl;
  }

}