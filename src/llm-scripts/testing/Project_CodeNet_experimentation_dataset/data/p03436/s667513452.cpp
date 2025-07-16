#include <bits/stdc++.h>

using namespace std;

int main() {
  int h,w;
  int shiro=0;
  cin>>h>>w;
  vector<vector<char>> data(h+2, vector<char>(w+2));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>data.at(i+1).at(j+1);
      if(data.at(i+1).at(j+1)!='#'){
        shiro++;
      }
    }
    
  }
  for(int i=0;i<w+2;i++){
    data.at(0).at(i)='#';
    data.at(h+1).at(i)='#';
  }
  for(int i=0;i<h;i++){
    data.at(i+1).at(0)='#';
    data.at(i+1).at(w+1)='#';
  }
  
  vector<int> dist((h+2)*(w+2), -1); // 全頂点を「未訪問」に初期化
    queue<int> que;
  

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[w+3] = 0;
    que.push(w+3); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
      vector<int> vec(4);
      vec.at(0)=v-w-2;
      vec.at(1)=v-1;
      vec.at(2)=v+1;
      vec.at(3)=v+w+2;

        // v から辿れる頂点をすべて調べる
        for (int nv : vec) {
          if(nv%(w+2)==0||nv%(w+2)==w+1){
            continue;
          }
          if(data.at(nv/(w+2)).at(nv%(w+2))=='#'){
            continue;
          }
         
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
      if(dist[w*h+w+2*h]==-1){
        
        cout<<-1<<endl;
        return 0;
      }
      else {
        
        cout<<shiro-dist[w*h+w+2*h]-1<<endl;
      }

  
  
}