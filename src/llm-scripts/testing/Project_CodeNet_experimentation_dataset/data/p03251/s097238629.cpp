#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

bool hantei( vector<int>& x, vector<int>& y ) {
  rep( Z, -100, 100+1 ) {
    bool flag = true;
    rep( i, 0, x.size() ) {
      if ( x.at(i) >= Z ) flag = false;
    }

    rep( i, 0, y.size() ) {
      if ( y.at(i) < Z ) flag = false;
    }
    if (flag) return false;
  }

  return true;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> x(N+1), y(M+1);
  cin >> x.at(0) >> y.at(0);
  rep(i, 1, N+1) cin >> x.at(i);
  rep(i, 1, M+1) cin >> y.at(i);

  cout << ( hantei(x, y) ? "War" : "No War" ) << endl;
}
