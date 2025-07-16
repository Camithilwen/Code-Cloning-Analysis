#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,Q,K;
  cin>>N;
  vector<vector<pair<int,int>>> A(N);
  for(int i=1;i<N;i++){
    int a,b,c;
    cin>>a>>b>>c;
    A[a-1].push_back({b-1,c});
    A[b-1].push_back({a-1,c});
  }
  cin>>Q>>K;
  vector<int> B(N,-1);
  queue<int> q;
  B[K-1]=0;
  q.push(K-1);
  while(!q.empty()){
    int I=q.front();
    q.pop();
    for(pair<int,int> p:A[I])
      if(B[p.first]==-1){
        B[p.first]=B[I]+p.second;
        q.push(p.first);
      }
  }
  while(Q--){
    int x,y;
    cin>>x>>y;
    cout<<B[x-1]+B[y-1]<<endl;
  }
}