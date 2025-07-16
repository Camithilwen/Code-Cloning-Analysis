#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  
  if (s.size() == 2) {
    cout << s << endl;
    return 0;
  }
  
  reverse(s.begin(),s.end());
  cout << s << endl;

  return 0;
}
