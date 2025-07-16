#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main(){
  
  int H, W, i, j, k;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
  queue<P> nxs;
  
  int cnt_sn = 0; //シャープの数
  int cnt_fn = 0; //フェイズ内の要素の数
  int cnt    = 0; // フェイズの数
  for(i = 0; i < H; i++){
    for(j = 0; j < W; j++){
      cin >> A.at(i).at(j);
      if(A.at(i).at(j) == '#'){
        nxs.push(P(i, j));
        cnt_sn++;
      }
    }
  }
  
  while(nxs.size() != 0 && cnt_sn < W * H){
     
    if(cnt_fn == 0){
      cnt++; cnt_fn = nxs.size();
    }
    P pos = nxs.front(); nxs.pop();
    for(i = 0; i < 4; i++){
      int x = pos.second + dx.at(i), y = pos.first + dy.at(i);
      if(x >= 0 && y >= 0 && x < W && y < H){
        if(A.at(y).at(x) == '.'){
          A.at(y).at(x) = '#';
          cnt_sn++;
          nxs.push(P(y, x));
        }
      }
    }
    cnt_fn--;
  }
  
  cout << cnt << endl;
  return 0;
}