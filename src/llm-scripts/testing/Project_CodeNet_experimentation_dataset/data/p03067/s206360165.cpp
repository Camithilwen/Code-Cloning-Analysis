#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> c >> b;
  if ((a >= b && b >= c) || (a <= b && b <= c)) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
