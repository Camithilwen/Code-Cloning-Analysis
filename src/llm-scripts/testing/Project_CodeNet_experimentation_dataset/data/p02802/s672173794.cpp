#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  int q;
  string s;
  set<int> ac;
  vector<int> wa(n+1, 0);
  for(int i=0; i<m; i++) {
    cin >> q >> s;
    if(ac.count(q)) continue;
    if(s=="AC") ac.insert(q);
    else wa[q]++;
  }
  
  for(int i=1; i<n+1; i++) if(!ac.count(i)) wa[i] = 0;
  cout << ac.size() << " " << accumulate(wa.begin(), wa.end(), 0) << endl;
  return 0;
}