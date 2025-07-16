#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  bool hflag = false, iflag = false;
  string ans = "Yes";
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == 'h') {
      if ((i < S.length() - 1) && S[i + 1] == 'i') {
        i++;
        continue;
      } else {
        ans = "No";
        break;
      }
    } else {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}