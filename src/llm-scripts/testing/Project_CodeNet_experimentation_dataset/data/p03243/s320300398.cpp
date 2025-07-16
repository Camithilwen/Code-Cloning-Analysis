#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  cin >> s;
  if (s[0] > s[1]) {
    cout << s[0] << s[0] << s[0] << endl;
  } else if (s[0] < s[1]) {
    cout << s[0] - '0' + 1 << s[0] - '0' + 1 << s[0] - '0' + 1 << endl;
  } else if (s[0] > s[2]) {
    cout << s[0] << s[0] << s[0] << endl;
  } else if (s[0] < s[2]) {
    cout << s[0] - '0' + 1 << s[0] - '0' + 1 << s[0] - '0' + 1 << endl;
  } else {
    cout << s << endl;
  }
  return 0;
}