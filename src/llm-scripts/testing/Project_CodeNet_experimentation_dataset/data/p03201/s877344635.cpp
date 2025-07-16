#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> cur (n);
  for (int i = 0; i < n; i++) {
    cin >> cur[i];
  }

  sort(cur.begin(), cur.end());

  int ans = 0;
  for (int k = 30; k >= 1; k--) {
    int target = 1 << k;

    vector<int> nxtl;
    vector<int> nxtr;
    
    int lptr = 0, rptr = cur.size() - 1;
    while (lptr <= rptr) {
      if (lptr == rptr) {
        nxtl.push_back(cur[lptr]);
        break;
      } else if (cur[lptr] + cur[rptr] == target) {
        ans++;
        lptr++;
        rptr--;
      } else if (cur[lptr] + cur[rptr] < target) {
        nxtl.push_back(cur[lptr]);
        lptr++;
      } else if (cur[lptr] + cur[rptr] > target) {
        nxtr.push_back(cur[rptr]);
        rptr--;
      }
    }

    reverse(nxtr.begin(), nxtr.end());
    for (int u : nxtr) {
      nxtl.push_back(u);
    }

    cur = nxtl;
  }

  cout << ans << endl;
}
