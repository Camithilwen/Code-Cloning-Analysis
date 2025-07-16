#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, D, X, Y;
  cin >> A >> B >> C >> D;
  X = min(A, B);
  Y = min(C, D);
  cout << X + Y << endl;
}