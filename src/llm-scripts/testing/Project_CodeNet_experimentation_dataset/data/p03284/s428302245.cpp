#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  if (n % k > 0) {
    ans = 1;
  }
  cout << ans << endl;
  return 0;
}
