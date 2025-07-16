#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string ans = "";
  while(n != 0){
    int t = n%(-2);
    if(t == -1) t = 1;
    ans.push_back('0'+t);
    n = (n-t)/(-2);
  }
  if(ans.size() == 0) ans = "0";
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
}