#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int a = Z;
  Z = Y; Y = X; X = a;
  cout << X << ' ' << Y << ' ' << Z << '\n';
  return 0;
}