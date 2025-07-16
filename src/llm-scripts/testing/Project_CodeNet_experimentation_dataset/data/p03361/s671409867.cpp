#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // Grid Repainting 2
  int h, w; cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s.at(i);

  vector<int> di = {1, 0, -1, 0};
  vector<int> dj = {0, 1, 0, -1};

  rep(i,h) {
    rep(j,w) {
      if (s.at(i).at(j) == '#') {
        int cnt = 0;
        rep(k,4) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (0 <= ni && ni < h && 0 <= nj && nj < w) {
            if (s.at(ni).at(nj) == '.') cnt++;
          }
        }
        if (cnt == 4) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}