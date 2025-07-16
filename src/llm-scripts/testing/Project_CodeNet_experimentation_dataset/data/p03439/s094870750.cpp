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
  ll N;
  cin >> N;
  string ret;
  vector<string> seats(N, "");
  cout << 0 << endl;
  cin >> ret;
  if (ret == "Vacant") return 0;
  seats[0] = ret;
  cout << N - 1 << endl;
  cin >> ret;
  if (ret == "Vacant") return 0;
  seats[N - 1] = ret;
  int l = 0, r = N - 1;
  int mid;
  while (true) {
    mid = (l + r) / 2;
    cout << mid << endl;
    cout << flush;
    cin >> ret;
    if (ret == "Vacant") {
      return 0;
    } else {
      seats[mid] = ret;
      if ((((mid - l) % 2 == 1) && seats[l] == seats[mid]) ||
          (((mid - l) % 2 == 0) && seats[l] != seats[mid])) {
        r = mid;
      } else {
        l = mid;
      }
    }
  }
  return 0;
}