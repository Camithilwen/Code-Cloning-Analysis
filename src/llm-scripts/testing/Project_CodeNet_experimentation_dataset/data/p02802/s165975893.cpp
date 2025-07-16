#include <bits/stdc++.h>
#define len(x) ((int)(x).size())

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  // [
  //   (count_WA_before_passed, is_passed)
  // ]
  vector<pair<int, bool>> contest_result(105000, make_pair(0, false));

  int WA_count = 0;
  int AC_count = 0;

  while (M--) {
    int p;
    string S;
    cin >> p >> S;
    if (contest_result[p].second) continue;

    if (S == "AC") {
      contest_result[p].second = true;
      AC_count++;
      WA_count += contest_result[p].first;
    } else if (S == "WA") {
      contest_result[p].first++;
    }
  }

  cout << AC_count << " " << WA_count << endl;
}
