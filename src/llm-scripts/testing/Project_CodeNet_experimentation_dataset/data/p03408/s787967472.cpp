#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<string> s(0);
  vector<int> p(0);
  rep(i, n) {
    string si;
    cin >> si;
    bool hit = false;
    rep(j, s.size()) {
      if (s.at(j) == si) {
        p.at(j)++;
        hit = true;
        break;
      }
    }
    if (!hit) {
      s.push_back(si);
      p.push_back(1);
    }
  }
  cin >> n;
  rep(i, n) {
    string si;
    cin >> si;
    rep(j, s.size()) {
      if (s.at(j) == si) {
        p.at(j)--;
        break;
      }
    }
  }
  int max = 0;
  rep(j, s.size()) if (p.at(j) > max) max = p.at(j);
  cout << max << endl;
}
