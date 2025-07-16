#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> x(3);
  int k, y;
  for(int i=0;i<3;i++) cin >> x.at(i);
  cin >> k;
  sort(x.begin(), x.end());
  y = x.at(2);
  for(int i=0;i<k;i++) y = 2*y;
  cout << x.at(0) + x.at(1) + y << endl;
}
