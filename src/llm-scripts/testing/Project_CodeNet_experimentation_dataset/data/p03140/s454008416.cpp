#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int cnt=0;
  string A,B,C;
  cin>>A>>B>>C;
  for(int i=0;i<N;i++){
    if((A.at(i) == B.at(i))&&(B.at(i) == C.at(i))) continue;
    if((A.at(i) != B.at(i))&&(B.at(i) == C.at(i))){
      cnt++;
      continue;
    }
    if((A.at(i) == B.at(i))&&(B.at(i) != C.at(i))){
      cnt++;
      continue;
    }    
    if((A.at(i) == C.at(i))&&(B.at(i) != C.at(i))){
      cnt++;
      continue;
    }
    cnt++;
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}
