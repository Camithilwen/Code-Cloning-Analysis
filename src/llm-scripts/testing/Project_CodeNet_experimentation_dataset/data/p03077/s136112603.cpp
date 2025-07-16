#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  ll min_move = min({a,b,c,d,e});
  cout << (n + min_move - 1) / min_move + 4 << endl;
  return 0;
}