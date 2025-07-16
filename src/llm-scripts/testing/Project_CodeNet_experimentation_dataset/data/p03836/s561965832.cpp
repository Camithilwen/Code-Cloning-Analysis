#include "bits/stdc++.h"
using namespace std;

// Inserted snippets: io, root
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
// End snippets

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int sx, sy, tx, ty;
  read(sx, sy, tx, ty);
  int dx = tx - sx, dy = ty - sy;
  write(
      "L" +
      string(dy + 1, 'U') +
      string(dx + 1, 'R') +
      "D" +
      "R" +
      string(dy + 1, 'D') +
      string(dx + 1, 'L') +
      "U" +
      string(dy, 'U') +
      string(dx, 'R') +
      string(dy, 'D') +
      string(dx, 'L')
      );
}
