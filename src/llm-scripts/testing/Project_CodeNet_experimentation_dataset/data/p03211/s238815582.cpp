#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  string S;
  cin >> S;
  int ans = INF;
  rep(i, 0, S.size() - 2) {
    int x = stoi(S.substr(i, 3));
    ans = min(ans, abs(753 - x));
  }
  cout << ans << endl;
  return 0;
}
