#include <bits/stdc++.h>
using namespace std;

int main(){
  cout<<fixed<<setprecision(12);
  int N,K;cin>>N>>K;
  vector<double> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  //vector<double> ans(N-K+1);
  priority_queue<double> ans;
  double X=0;
  for(int i=0;i<K;i++) X+=(A.at(i)+1.0)/2;
  ans.push(X);
  for(int i=1;i<N-K+1;i++){
    X-=(A.at(i-1)+1.0)/2;
    X+=(A.at(i+K-1)+1.0)/2;
    ans.push(X);
  }
  cout<<ans.top()<<endl;
}
  
  
  
