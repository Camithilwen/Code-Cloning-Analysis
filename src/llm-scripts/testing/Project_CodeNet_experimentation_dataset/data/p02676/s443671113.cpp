#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;
  
  if (s.size() <= k) cout << s << endl;
  else {
    for (int i = 0; i < k; i++) {
      cout << s.at(i);
    }
    cout << "..." << endl;
  }
}