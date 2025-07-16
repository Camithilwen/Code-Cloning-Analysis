#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int A, B, C, D;

int main(int argc, char* argv[]) {
  cin >> A >> B >> C >> D;
  int L = A + B;
  int R = C + D;

  if (L > R)
    cout << "Left" << endl;
  else if (L == R)
    cout << "Balanced" << endl;
  else
    cout << "Right" << endl;

  return 0;
}