#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
  int H,W,i,j,a;scanf("%d%d",&H,&W);
  bool odd[H][W];
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      scanf("%d",&a);
      odd[i][j] = a&1;
    }
  }
  bool coin = false;vector<pair<pair<int,int>,pair<int,int>>> v;
  i = 0;j = 0;int ni,nj;
  while(true){
    if((!(i&1)) && j+1 == W){
      ni = i+1;nj = j;
    }
    else if(i&1 && j == 0){
      ni = i+1;nj = j;
    }
    else if(!(i&1)){
      ni = i;nj = j+1;
    }
    else{
      ni = i;nj = j-1;
    }
    if(ni == H) break;
    if(odd[i][j]){
      if(coin == false){
        coin = true;
        v.push_back(make_pair(make_pair(i,j),make_pair(ni,nj)));
      }
      else{
        coin = false;
      }
    }
    else{
      if(coin == true){
        v.push_back(make_pair(make_pair(i,j),make_pair(ni,nj)));
      }
    }
    i = ni;j = nj;
  }
  printf("%d\n",v.size());
  for(i=0;i<v.size();i++) printf("%d %d %d %d\n",v[i].first.first+1,v[i].first.second+1,v[i].second.first+1,v[i].second.second+1);
}