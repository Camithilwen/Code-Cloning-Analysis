#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;

int main(){
  int h, w;
  cin >> h >> w;
  
  map<int,int> ns; //（現在地、スタート地点の最大値）
  multiset<int> dist; //現在地ースタート地点の最大値
  
  rep(i,w) ns[i] = i; //キーiにiを代入
  rep(i,w) dist.insert(0); //はじめは距離0
  
  rep(i,h){
    int a, b;
    cin >> a >> b;
    --a; --b;
    
    auto it = ns.lower_bound(a);
    int ms = -1; //最も右にある開始点を保持
    while(1){
      //壁を1だけ超えるスタート地点を取得（b+1）
      if(it == ns.end() || it -> first > b+1) break;
      ms = max(ms, it -> second);
      dist.erase(dist.find(it->first - it->second));
      ns.erase(it++);
    }
    //要素が見つからない、wを超えてしまう時を除く。
    if(ms != -1 && b+1 != w){
      dist.insert(b+1 - ms);
      ns[b+1] = ms; 
    }
    
    int ans = -1;
    if(dist.size() > 0){
      ans = *dist.begin();
      ans += i+1;
    }
    cout << ans << endl;
  }
    
  return 0;
}