#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
  ll h,w;
  cin >> h >> w;
  string s[h];
  vector<vector<char>> t(h, vector<char>(w));
  rep(i,h) cin >> s[i];
  rep(i,h)rep(j,w) t[i][j]='.';
  
  rep(i,h)rep(j,w){
    if(s[i][j]=='.') continue;
    rep(k,4){
      int ii = i+dx[k];
      int jj = j+dy[k];
      if(ii<0 || ii>h-1) continue;
      if(jj<0 || jj>w-1) continue;
      if(s[ii][jj]=='#'){
        t[ii][jj]='#';
        t[i][j]='#';
        break;
      }
    }
  }
  int cnt=0;
  rep(i,h)rep(j,w){
    if(s[i][j]==t[i][j]) cnt++;
  }
  if(cnt==h*w) cout << "Yes" << endl;
  else cout << "No" << endl;
}