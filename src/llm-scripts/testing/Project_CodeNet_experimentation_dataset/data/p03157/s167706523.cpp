#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

vector<vector<pair<int,int>>> parent;

pair<int,int> find(pair<int,int> x){
  pair<int,int> y=parent.at(x.first).at(x.second);
  if(y!=x){
    y=find(y);
  }
  return parent.at(x.first).at(x.second)=y;
}

void unite(pair<int,int> x, pair<int,int> y){
  pair<int,int> a=find(x);
  pair<int,int> b=find(y);
  if(a!=b){
    parent.at(a.first).at(a.second)=b;
  }
}

int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> c(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>c.at(i).at(j);
    }
  }
  parent.resize(H,vector<pair<int,int>>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      parent.at(i).at(j)=make_pair(i,j);
    }
  }
  int dx[4]={1,0,-1,0};
  int dy[4]={0,1,0,-1};
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      for(int k=0;k<4;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni<0||nj<0||ni>=H||nj>=W){
          continue;
        }
        if(c.at(i).at(j)!=c.at(ni).at(nj)){
          unite(make_pair(i,j),make_pair(ni,nj));
        }
      }
    }
  }
  vector<vector<ll>> number1(H,vector<ll>(W,0)),number2(H,vector<ll>(W,0));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      pair<int,int> p=find(make_pair(i,j));
      if(c.at(i).at(j)=='.'){
        number1.at(p.first).at(p.second)++;
      }else{
        number2.at(p.first).at(p.second)++;
      }
    }
  }
  ll ans=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      ans+=number1.at(i).at(j)*number2.at(i).at(j);
    }
  }
  cout<<ans<<endl;
}
