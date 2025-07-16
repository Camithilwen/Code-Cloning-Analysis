#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,m,x,y,flg = 0;
  cin >> n >> m >> x >> y;
  vector<int> X(n), Y(m);

  rep(i,n) cin >> X[i];
  rep(i,m) cin >> Y[i];

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  for (int i = x+1; i <= y; i++) {
    if (X[n-1] < i && i <= Y[0]) {
      flg = 1;
      break;
    }
  }
  if (flg) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}