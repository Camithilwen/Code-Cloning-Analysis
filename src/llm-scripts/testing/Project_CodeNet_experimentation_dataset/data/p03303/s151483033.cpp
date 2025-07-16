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
  string S;
  int w;
  cin >> S >> w;
  int i = 0;
  string ans = "";
  ans += S[0];
  while (i + w < S.length()) {
    i = i + w;
    ans += S[i];
  }
  cout << ans << endl;
  return 0;
}