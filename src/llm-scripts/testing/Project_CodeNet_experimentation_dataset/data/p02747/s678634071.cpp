#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  bool flg = true;
  rep(i, s.size()){
    if(i % 2 == 0 && s[i] == 'h' && s[i+1] == 'i') continue;
    else if(i % 2 == 1) continue;
    else{
      flg = false;
      cout << "No" << endl;
      break;
    }
  }
  if(flg) cout << "Yes" << endl;
  return 0;
}
