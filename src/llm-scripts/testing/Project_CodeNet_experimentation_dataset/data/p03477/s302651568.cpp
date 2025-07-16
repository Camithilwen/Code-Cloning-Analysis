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
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  if (A + B < C + D) {
    cout << "Right" << endl;
  } else if (A + B > C + D) {
    cout << "Left" << endl;
  } else {
    cout << "Balanced" << endl;
  }
  return 0;
}