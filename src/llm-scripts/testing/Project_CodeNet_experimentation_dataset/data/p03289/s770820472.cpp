#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  cin >> s;

  string ans = "AC";
  if(s[0] != 'A'){
    ans = "WA";
  }
  int cnt = 0, m;
  for(int i = 2; i <= s.size() - 2; i++){
    if(s[i] == 'C') {
      cnt++;
      m = i;
    }
  }
  if(cnt != 1) ans = "WA";
    rep(i,s.size()){
      if (i == 0 || i == m) continue;
      if(s[i] < 'a' || s[i] > 'z') ans = "WA";
    }
  
  cout << ans << endl;
  return 0;
}
