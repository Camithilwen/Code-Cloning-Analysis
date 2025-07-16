#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int X = A + B, Y = C + D;

  if (X > Y) cout << "Left" << endl;
  else if (X == Y) cout << "Balanced" << endl;
  else if (X < Y) cout << "Right" << endl;
}
  
