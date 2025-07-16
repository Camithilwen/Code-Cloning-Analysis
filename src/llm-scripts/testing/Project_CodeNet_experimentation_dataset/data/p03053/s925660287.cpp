#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

vector<vector<char>> vec;
vector<pair<int, int>> direct = {{1,0},{-1, 0}, {0,1}, {0, -1}};
vector<vector<int>> dist;
queue<pair<int, int>> que;
int H, W;

int
bfs()
{

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    rep(i, 0, 4){
      int dx = x + direct[i].first;
      int dy = y + direct[i].second;
      if(dx < 0 || dx >= H || dy < 0 || dy >= W) continue;
      if(vec[dx][dy] == '#') continue;
      if(dist[dx][dy] == -1){
        dist[dx][dy] = 1 + dist[x][y];
        que.push({dx, dy});
      }
    }
  }

  int ans = 0;
  rep(i, 0,H){
    rep(k, 0, W){
      ans = max(ans, dist[i][k]);
    }
  }
  return ans;
}

int 
main() {

  cin >> H >> W;
  vec.resize(H);
  dist.resize(H, vector<int>(W, -1));
  rep(i, 0, H){
    rep(k, 0, W){
      char c; cin >> c;
      vec[i].push_back(c);
      if(vec[i][k] == '#') dist[i][k] = 0, que.push({i, k});
    }
  }

  int ans = bfs();


  cout << ans << endl;

}
