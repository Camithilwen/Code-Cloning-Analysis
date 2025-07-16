#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {

  vector<queue<char>> v(3);
  string s;

  rep(i, 0, 3) {
    cin >> s;
    for (char c : s) {
      v[i].push(c);
    }
  }

  int tmp, x = 0;

  while (true) {
    if (v[x].empty()) {
      break;
    }
    tmp = x;
    x = v[x].front() - 'a';
    v[tmp].pop();
  }

  cout << char(x + 'A') << endl;
  getchar();
}