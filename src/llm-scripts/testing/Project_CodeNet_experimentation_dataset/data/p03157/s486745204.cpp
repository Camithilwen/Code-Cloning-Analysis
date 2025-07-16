#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
const int INF = 100000000;
typedef long long ll;

int W,H;
int sy, sx, gy, gx;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool movable(vector<vector<char>> &c, vector<vector<int>> &mat, int h, int w, int hb, int wb) {
  if ((h<0) || (h>=H) || (w<0) || (w>=W)) {
    return false;
  }
  else if (mat[h][w]!=INF || (c[h][w]==c[hb][wb])) {
    return false;
  }
  else {
    return true;
  }
}


ll bfs(vector<vector<char>> &c, vector<vector<int>> &mat, pair<int,int> &q) {
  ll k,s;
  s=0;
  k = 1;
  queue<P> que;
  que.push(q);
  
  if (mat[q.first][q.second] != INF) return 0;
  else (mat[q.first][q.second] = 0);

  while(que.size()) {
    P p = que.front();
    que.pop();

    rep(i,4){
      if (movable(c,mat,p.first+dy[i],p.second+dx[i],p.first,p.second)) {
        que.push(P(p.first+dy[i],p.second+dx[i]));
        mat[p.first+dy[i]][p.second+dx[i]]=mat[p.first][p.second]+1;
        if (c[p.first+dy[i]][p.second+dx[i]]=='.') s++;
        else k++;
      }
    }
  }
  return k*s;
}

int main() {
  cin >> H >> W;

  vector<vector<char>> c(H,vector<char> (W));
  vector<pair<int,int>> P;
  rep(h,H) {
      string s;
      cin >> s;
    rep(w,W) {
      c[h][w] = s[w];
      if (s[w]=='#') {
          P.push_back(make_pair(h,w));
      }
    }
  }
  vector<vector<int>> mat(H,vector<int> (W, INF));
  ll ans = 0;
  for (auto p: P) {
    ll tmp = bfs(c,mat,p);
    ans += tmp;

  }
    cout << ans << endl;
}