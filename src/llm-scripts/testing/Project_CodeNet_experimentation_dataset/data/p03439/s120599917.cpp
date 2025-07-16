#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
const string V = "Vacant";
int main() {
  ll N;
  cin >> N;
  string l, r;
  cout << 0 << endl << flush;
  cin >> l;
  cout << endl;
  if (l == V) return 0;
  cout << N - 1 << endl << flush;
  cin >> r;
  cout << endl;
  if (r == V) return 0;
  int l_num = 0, r_num = N - 1;
  while (true) {
    int mid_num = (l_num + r_num) / 2;
    string mid;
    cout << mid_num << endl << flush;
    cin >> mid;
    cout << endl;
    if (mid == V) return 0;
    int num = mid_num - l_num;
    if (num % 2 == 1 && mid == l) {
      r_num = mid_num;
      r = mid;
      continue;
    } else if (num % 2 == 0 && mid != l) {
      r_num = mid_num;
      r = mid;
      continue;
    }
    l = mid;
    l_num = mid_num;
  }
}