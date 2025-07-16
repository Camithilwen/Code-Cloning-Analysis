#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;

  int ans = INF;
  rep(i,s.size()-2){
    string t = "";
    t+=s[i];
    t+=s[i+1];
    t+=s[i+2];
    int tmp = stoi(t);
    ans = min(ans,abs(753-tmp));
  }

  cout << ans << endl;
  
  return 0;
}
