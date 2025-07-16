#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
int memo[10001],color[10001];
stack<int> numb;
vector<int> connect[10001],rconnect[10001];

void dfs(int i){
  if(memo[i]!=0) return;
  memo[i]=1;
  lp(j,connect[i].size()){
    dfs(connect[i][j]);
  }
  numb.push(i);
  return;
}

void rdfs(int i,int j){
  if(memo[i]!=1) return;
  memo[i]=2;
  color[i]=j;
  lp(k,rconnect[i].size()){
    rdfs(rconnect[i][k],j);
  }
  return;
}

int main(){
  int v,e;
  cin>>v>>e;
  lp(i,e){
    int a,b;
    cin>>a>>b;
    connect[a].push_back(b);
    rconnect[b].push_back(a);
  }
  for(int i=0;i<v;i++){
    if(memo[i]==0) {
      dfs(i);
    }
  }
  int j=0;
  for(int i=0;i<v;i++){
    int x=numb.top();
    numb.pop();
    if(memo[x]==1) {
      rdfs(x,j);
      j++;
    }
  }
  int q;
  cin>>q;
  lp(i,q){
    int a,b;
    cin>>a>>b;
    if(color[a]==color[b]) cout<<"1"<<endl;
    else cout<<"0"<<endl;
  }
  
  return 0;
}

