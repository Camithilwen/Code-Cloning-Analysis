#include<bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int main(void){
  int n;
  cin>>n;
  vector<P> red,blue;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    red.push_back({a,b});
  }
  for(int i=0;i<n;i++){
    int c,d;
    cin>>c>>d;
    blue.push_back({c,d});
  }
  sort(blue.begin(),blue.end());
  vector<bool> tf(n,false);
  int cnt=0;
  for(int i=0;i<n;i++){
    int bx=blue[i].first;
    int by=blue[i].second;
    int y=-1000;
    int x=-1;
    for(int j=0;j<n;j++){
      if(tf[j]){
        continue;
      }
      int rx=red[j].first;
      int ry=red[j].second;
      if(bx<rx){
        continue;
      }
      if(by<ry){
        continue;
      }
      if(y<ry){
        x=j;
        y=ry;
      }
    }
    if(x!=-1){
      ++cnt;
      tf[x]=true;
    }
  }
  cout<<cnt<<endl;
  return 0;
}