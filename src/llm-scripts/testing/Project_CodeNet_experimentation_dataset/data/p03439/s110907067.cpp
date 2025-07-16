#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int l = 1, r = n - 1;
  string ls, rs;
  
  cout << 1 << endl;
  cin >> ls;
  if (ls == "Vacant") return 0;
  
  cout << n - 1 << endl;
  cin >> rs;
  if (rs == "Vacant") return 0;
  
  if (ls != rs) {
    cout << 0 << endl;
    string s;
    cin >> s;
    return 0;
  }
  
  while (true) {
    int mid = (l + r) / 2;
    cout << mid << endl;
    string ms;
    cin >> ms;
    if (ms == "Vacant") return 0;
    if ((mid - l) % 2 == 0 && ms != ls) {
      r = mid;
      rs = ms;
    }
    else if ((mid - l) % 2 == 1 && ms == ls) {
      r = mid;
      rs = ms;
    }
    else if ((r - mid) % 2 == 0 && ms != rs) {
      l = mid;
      ls = ms;
    }
    else if ((r - mid) % 2 == 1 && ms == rs) {
      l = mid;
      ls = ms;
    }
  }
}