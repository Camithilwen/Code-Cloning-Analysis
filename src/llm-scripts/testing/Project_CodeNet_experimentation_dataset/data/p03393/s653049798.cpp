#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string S, ans;
  cin >> S;
  if (S.size() == 26) {
    ans = S;
    if (!next_permutation(begin(ans), end(ans)))
      ans = "-1";
    else
      for (int i = 0; i != 26; ++i) {
        if (S[i] != ans[i]) {
          ans.resize(i + 1);
          break;
        }
      }
  } else {
    int d[26]{};
    for (char c : S) ++d[c - 'a'];
    ans = S + char('a' + find(d, d + 26, 0) - d);
  }
  cout << ans << endl;
}
