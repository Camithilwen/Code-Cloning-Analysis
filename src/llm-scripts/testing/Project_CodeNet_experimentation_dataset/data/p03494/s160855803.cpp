#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A(210);

int main() {
  cin>>N;
  for(int i=0;i<N;i++) cin>>A.at(i);
  int count=0;
  
  while(true){
    bool exist_odd=false;
    for(int i=0;i<N;i++){
      if(A.at(i)%2!=0) exist_odd=true;
    }
    
    if(exist_odd) break;
    
    for(int i=0;i<N;i++){
     A.at(i)/=2;
    }
    count++;
  }
  
  cout<<count<<endl;
  return 0;
}