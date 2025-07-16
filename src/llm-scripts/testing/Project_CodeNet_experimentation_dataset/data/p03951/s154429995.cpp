#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  string s, t;
  cin >> N;
  cin >> s >> t;
  
  int len=s.size() + t.size();
  rep(i,s.size()) {
    if (t.find(s.substr(i)) != string::npos) {
      len -= (s.size() - i);
      break;
    }
  }
  
  cout << len << endl;
  return 0;
}
