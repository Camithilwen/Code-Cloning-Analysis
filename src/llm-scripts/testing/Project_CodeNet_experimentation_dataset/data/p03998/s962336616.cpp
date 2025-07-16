#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<string> vs(3);
  for (int i = 0; i < 3; ++i) {
    cin >> vs[i];
  }

  vector<int> cur(3, 0);
  int t = 0;
  char ans;
  while (true) {
    if (cur[t] >= vs[t].size()) {
      ans = 'A' + t;
      break;
    }

    cur[t]++;
    t = vs[t][cur[t] - 1] - 'a';
  }

  cout << ans << '\n';
}