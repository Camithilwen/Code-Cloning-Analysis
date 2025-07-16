#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  vector<int64_t>B(1+N);
  map<int64_t,int64_t>M;
  M[1]=A.at(0);
  for(int i=2;i<=N;i++)
    if(i%2==1)
      M[i]=M.at(i-2)+A.at(i-1);
  B.at(0)=0;
  B.at(0)=0;
  B.at(2)=max(A.at(0),A.at(1));
  for(int i=3;i<=N;i++){
  if(i%2==0)
    B.at(i)=max(A.at(i-1)+B.at(i-2),A.at(i-2)+M.at(i-3));
    else
      B.at(i)=max(A.at(i-1)+B.at(i-2),A.at(i-2)+B.at(i-3));
  
  }cout<<B.at(N)<<endl;
   return 0;
}