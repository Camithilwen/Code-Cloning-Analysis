#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m; cin >> n >> m;
  vector<int> xt(n+1); cin >> xt[0];
  vector<int> yt(m+1); cin >> yt[0];
  for (int i=1; i<n+1; i++) cin >> xt.at(i);
  for (int i=1; i<m+1; i++) cin >> yt.at(i);
  sort(xt.begin(), xt.end());
  sort(yt.begin(), yt.end());
  
  if (xt[n] >= yt[0]) {
    cout << "War" << endl;
  } else {
    cout << "No War" << endl;
  }
  
  return 0;
}