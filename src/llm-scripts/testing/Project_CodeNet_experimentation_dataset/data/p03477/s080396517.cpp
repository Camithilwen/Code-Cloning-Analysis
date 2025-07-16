#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

const ld pi = 3.141592653589793;

int w[4];

int main() {
  for (int i = 0; i < 4; i++) {
    cin >> w[i];
  }

  if (w[0] + w[1] > w[2] + w[3]) {
    cout << "Left" << endl;
    return 0;
  }
  if (w[0] + w[1] == w[2] + w[3]) {
    cout << "Balanced" << endl;
    return 0;
  }

  if (w[0] + w[1] < w[2] + w[3]) {
    cout << "Right" << endl;
    return 0;
  }
}