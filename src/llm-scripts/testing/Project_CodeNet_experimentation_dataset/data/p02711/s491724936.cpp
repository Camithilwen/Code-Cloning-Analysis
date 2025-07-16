#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string N, ans = "No";
  cin >> N;
  for(char s : N) {
    if (s == '7') ans = "Yes";
  }
  cout << ans << endl;
}
