#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  char c[n][m];
  rep(i, n){
    rep(j, m) cin >> c[i][j];
  }
  
  string s = "Yes";
  int cnt;
  rep(i, n){
    rep(j, m){
      if(c[i][j] == '.') continue;
      cnt = 0;
      if(i != 0 && c[i - 1][j] == '#') cnt++;
      if(i != n - 1 && c[i + 1][j] == '#') cnt++;
      if(j != 0 && c[i][j - 1] == '#') cnt++;
      if(j != m - 1 && c[i][j + 1] == '#') cnt++;
      if(cnt == 0) {
        s = "No";
      }
    }
  }
  cout << s << endl;
       

  return 0;
}