#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, D, E, X;
  cin >> A >> B >> C >> D >> E >> X;
  int ma, mi;
  ma = max(max(max(max(A, B), C), D), E);
  mi = min(min(min(min(A, B), C), D), E);
  if(ma - mi > X) {
    cout << ":(" << endl;
  }
  else {
    cout << "Yay!" << endl;
  }
}