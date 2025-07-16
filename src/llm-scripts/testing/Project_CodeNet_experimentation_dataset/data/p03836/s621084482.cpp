#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  const int dx = tx - sx, dy = ty - sy;

  // print string(how many, what)
  cout << string(dy, 'U') << string(dx, 'R');  // path 1 (s->t)
  cout << string(dy, 'D') << string(dx, 'L');  // path 2 (t->s)
  cout << 'L' << string(dy+1, 'U') << string(dx+1, 'R') << 'D';  // path 3 (s->t)
  cout << 'R' << string(dy+1, 'D') << string(dx+1, 'L') << 'U';  // path 4 (t->s)
  cout << endl;
}