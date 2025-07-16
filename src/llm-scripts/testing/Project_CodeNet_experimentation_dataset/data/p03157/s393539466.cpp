#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
 
int dy[] = {1,0};
int dx[] = {0,1};
 
struct UnionFind{
    vector<int> data;
    int __size;
    UnionFind(int sz) {
    data.assign(sz, -1);
    __size = sz;
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);//親は負でサイズを保存
    __size--;
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  bool same(int x, int y){
      return find(x) == find(y);
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
 
  int unum() {
    return (__size);
  }
};
 
int main(){ 
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  map<int,ll> mp;
  UnionFind uf(h*w);
  vector<int> b; 
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int k = 0; k < 2; k++) {
        int ny = i + dy[k], nx = j + dx[k];
        if (ny >= h || nx >= w) continue;
        if (uf.same(i*w+j,ny*w+nx)) continue;
        if (s[i][j] != s[ny][nx]) uf.unite(i*w+j, ny*w+nx); 
      }
    }
  }
  ll res = 0;
  rep(i,h) rep(j,w) if (s[i][j] == '#') mp[uf.find(i*w+j)]++;
  rep(i,h) rep(j,w) if (s[i][j] == '#') res += uf.size(i*w+j) - mp[uf.find(i*w+j)];
  cout << res << endl;
  return 0;
} 