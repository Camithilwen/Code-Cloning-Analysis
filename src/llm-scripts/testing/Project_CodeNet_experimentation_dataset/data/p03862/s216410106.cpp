#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

ifstream fin("../data.txt");

int n, x, a1, a2, eat;
long long ans;

int main() {

  cin >> n >> x >> a1;
  n--;
  while (n--) {
    cin >> a2;
    if (a1 + a2 > x) {
      eat = a1 + a2 - x;
      ans += eat;
      if (eat > a2) {
        a2 = 0;
      } else {
        a2 -= eat;
      }
    }
    a1 = a2;
  }
  cout << ans;
  return 0;
}
