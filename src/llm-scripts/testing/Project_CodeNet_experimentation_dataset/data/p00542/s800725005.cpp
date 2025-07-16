#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define all(c) (c).begin(), (c).end()


int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  int s = A + B + C + D;
  s -= min(min(A, B), min(C, D));
  cout << s + max(E, F) << "\n";
  return 0;
}