#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  int l[m],r[m];

  for(int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
  }

  int ans = *max_element(l,l+m) - *min_element(r,r+m);
  if(ans > 0) {
    cout << 0 << endl;
  }else {
    cout << abs(ans)+1 << endl;
  }
  return 0;
}