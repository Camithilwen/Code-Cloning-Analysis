#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

int main() {
  int A , B;
  cin >> A >> B;

  int MAX = max(A, B), MIN = min(A, B);
  if (MAX == 1) {
    cout << "1 2\n.#" << BR;
    return 0;
  }
  string S = ".#";
  if (MAX == A) S = "#.";

  int H = 90, W = 80;
  vector<vector<ll>> cells(H, vector<ll>(W , 0));

  int h = 1, w = 1;
  while(MAX > 1) {
    cells[h][w] = 1;
    if (w + 2 < W) {
      w += 2;
    } else {
      h += 3;
      w = 1;
    }
    MAX--;
  }

  if (MIN > 1) rep(i, h + 2, H) rep0(j, W) cells[i][j] = 1;
  else cells[H - 1][W - 1] = 1;

  h += 3;
  w = 1;
  MIN--;
  while(MIN > 0) {
    cells[h][w] = 0;
    if (w + 2 < W) {
      w += 2;
    } else {
      h += 3;
      w = 1;
    }
    MIN--;
  }

  cout << H << SP << W << BR;
  rep0(i, H) {
    rep0(j, W) {
      cout << S[cells[i][j]];
    }
    cout << BR;
  }

  return 0;
}