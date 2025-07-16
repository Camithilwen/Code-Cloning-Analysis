#include <bits/stdc++.h>
using namespace std;

int main() {
  string x, y, z;
  bool s = false;
  bool t = false;
  cin >> x >> y >> z;
  if(x[x.size()-1] == y[0]){s = true;}
  if(y[y.size()-1] == z[0]){t = true;}
  if(s*t == 1){cout << "YES" << endl;}
  else{cout << "NO" << endl;}
}