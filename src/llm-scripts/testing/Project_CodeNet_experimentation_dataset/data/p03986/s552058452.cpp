#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  string str;
  cin >> str;
  int s = 0;
  int t = 0;
  int remove_count = 0;
  REP(i, str.length()) {
    if (str[i] == 'S') {
      s++;
    } else {
      if (s > 0) {
        s--;
        remove_count += 2;
      }
    }
  }
  cout << str.length() - remove_count << endl;
}