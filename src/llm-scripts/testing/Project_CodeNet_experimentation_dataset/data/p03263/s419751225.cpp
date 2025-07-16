#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

struct memo {
  int x;
  int y;
  int xx;
  int yy;
};

int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  rep(i, H)rep(j, W) cin >> a[i][j];
  vector<memo> vec;
  rep(i, H)rep(j, W) {
    if (a[i][j]%2) {
      memo tmp;
      tmp.x = j+1;
      tmp.y = i+1;
      if (j < W-1) {
        tmp.xx = j+2;
        tmp.yy = i+1;
        a[i][j+1]++;
        vec.push_back(tmp);
      }
      else if (i < H-1){
        tmp.xx = j+1;
        tmp.yy = i+2;
        a[i+1][j]++;
        vec.push_back(tmp);
      }
    }
  }
  cout << vec.size() << endl;
  rep(i, vec.size()) {
    cout << vec[i].y << " " << vec[i].x << " " << vec[i].yy << " " << vec[i].xx << endl;
  }
}
