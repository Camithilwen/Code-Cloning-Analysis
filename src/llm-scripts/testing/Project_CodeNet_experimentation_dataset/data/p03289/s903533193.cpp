#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  if (S[0] != 'A') {
    cout << "WA" << endl;
    return 0;
  }

  for (char c : S) {
    if (c == 'A' || c == 'C') continue;
    if (isupper(c)) {
      cout << "WA" << endl;
      return 0;
    }
  }

  int cnt = 0;
  for (int i = 2; i < S.size() - 1; ++i) {
    if (S[i] == 'C') ++cnt;
  }

  if (cnt == 1) cout << "AC" << endl;
  else cout << "WA" << endl;
  return 0;
}
