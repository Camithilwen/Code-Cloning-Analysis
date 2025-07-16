#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int R; cin >> R;
  if (R < 1200) cout << "ABC" << endl;
  else if (R < 2800) cout << "ARC" << endl;
  else               cout << "AGC" << endl;
}
