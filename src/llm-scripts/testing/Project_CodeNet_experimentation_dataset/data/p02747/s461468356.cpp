#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  string s; cin >> s;
  if (s.size()%2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  for(int i=0; i<s.size(); i+=2) {
    if (s[i] == 'h' && s[i+1] == 'i') continue;
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}

// EOF