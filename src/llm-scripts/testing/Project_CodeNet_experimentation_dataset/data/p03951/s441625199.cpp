#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  string s,t;
  cin >> n >> s >> t;
  int ans = 2*n;
  rep(i,1,n+1){
    if(s.substr(n-i,i) == t.substr(0,i)) ans = 2*n-i;
  }
  cout << ans << endl;
}