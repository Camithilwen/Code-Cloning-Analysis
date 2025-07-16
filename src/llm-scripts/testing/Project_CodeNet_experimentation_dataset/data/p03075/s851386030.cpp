#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int ma = 0, mi = 999;
  for (int i=0; i<5; i++) {
    cin >> a;
    ma = max(ma, a); 
    mi = min(mi, a);
  }
  int dist = ma - mi;
  int k;
  cin >> k;
  if (dist <= k) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}
