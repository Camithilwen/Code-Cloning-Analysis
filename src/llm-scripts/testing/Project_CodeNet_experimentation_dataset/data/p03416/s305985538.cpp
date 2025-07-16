#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B; cin >> A >> B;
  int cnt = 0;
  for (int i = A; i <= B; ++i) {
    string s = to_string(i);
    int n = s.size();
    bool ok = true;
    for (int i = 0; i < n/2; ++i) {
      if (s[i] != s[n-i-1]) {
        ok = false;
        break;
      }
    }
    if (ok) ++cnt;
  }
  cout << cnt << endl;
}
