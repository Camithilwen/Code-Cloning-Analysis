#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  string ans = "";
  for (int i = 0; i < 2; i++) {
    string head = "";
    head += string(ty - sy + i, 'U');
    head += string(tx - sx + i, 'R');
    head = string(i, 'L') + head;
    head += string(i, 'D');

    string tail = "";
    tail += string(ty - sy + i, 'D');
    tail += string(tx - sx + i, 'L');
    tail = string(i, 'R') + tail;
    tail += string(i, 'U');
    
    ans += head + tail;
  }

  cout << ans << endl;
  return 0;
}
