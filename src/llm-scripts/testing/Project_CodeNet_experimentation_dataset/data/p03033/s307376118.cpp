#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Q;
  cin>>N>>Q;
  int I=1100100100;
  vector<pair<int,int>> p;
  for(int i=0;i<N;i++){
    int a,b,c;
    cin>>a>>b>>c;
    p.push_back(make_pair(a-c,c));
    p.push_back(make_pair(b-c,-1*c));
  }
  for(int i=0;i<Q;i++){
    int a;
    cin>>a;
    p.push_back(make_pair(a,I));
  }
  sort(p.begin(),p.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  priority_queue<int, vector<int>, greater<int>> end;
  for(int i=0;i<2*N+Q;i++){
    int a,b;
    tie(a,b)=p[i];
    if(b<0){
      end.push(b*-1);
    }
    else if(b<I){
      pq.push(b);
    }
    else{
      while(!pq.empty()&&!end.empty()){
        if(pq.top()!=end.top()){
          break;
        }
        pq.pop();
        end.pop();
      }
      if(pq.empty()){
        cout<<"-1"<<endl;
      }
      else{
        cout<<pq.top()<<endl;
      }
    }
  }
}