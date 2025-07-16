#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B; cin >> A >> B;
  if (A == B) cout << 2 * A << endl;
  else if (A > B) cout << 2 * A - 1 << endl;
  else cout << 2 * B - 1 << endl;
}
