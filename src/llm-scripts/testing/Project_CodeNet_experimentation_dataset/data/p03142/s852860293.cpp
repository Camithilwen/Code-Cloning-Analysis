#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N,M;
  cin>>N>>M;
  Graph G(N);
  vector<int> count(N,0);
  for(int i=0;i<N+M-1;i++){
    int A,B;
    cin>>A>>B;
    A--,B--;
    G.at(A).push_back(B);
    count.at(B)++;
  }

  int root;
  for(int i=0;i<N;i++){
    if(count.at(i)==0){
      root=i;
    }
  }

  vector<int> parent(N,-1);
  stack<int> s;
  s.push(root);
  while(!s.empty()){
    int v=s.top();
    s.pop();
    for(auto nv:G.at(v)){
      if(count.at(nv)>1){
        count.at(nv)--;
      }else{
        parent.at(nv)=v;
        s.push(nv);
      }
    }
  }

  for(int i=0;i<N;i++){
    cout<<parent.at(i)+1<<endl;
  }
}
