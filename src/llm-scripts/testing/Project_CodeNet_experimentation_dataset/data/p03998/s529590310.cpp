#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  vector<queue<char>> s(3);
  rep(i,3) {
    string t; cin >> t;
    rep(j,t.size()) s[i].push(t[j]);
  }
  int turn = 0;
  //!s[0].empty()&&!s[1].empty()&&!s[2].empty()
  while (true)
  {
    if (s[turn].empty()) break;
    char c = s[turn].front(); s[turn].pop();
    if (c == 'a') turn = 0;
    else if (c=='b') turn = 1;
    else turn = 2;
  }
  if (turn==0) cout << 'A' << endl;
  else if (turn==1) cout << 'B' << endl;
  else cout << 'C' << endl;
  return 0;
}