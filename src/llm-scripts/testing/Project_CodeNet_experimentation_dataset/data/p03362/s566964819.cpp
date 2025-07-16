#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<bool>A(55556,true);
  for(int i=2;i<55556;i++){
  if(!A.at(i))
    continue;
    else{
    for(int j=2;i*j<=55555;j++)
      A.at(i*j)=false;
    }
   }int a=0;
  vector<int>B;
  for(int i=2;i<55556;i++){
  if(A.at(i)){if(i%5==1){B.push_back(i);a++;}}
  if(a==N)break;
  }for(int i=0;i<N-1;i++)
    cout<<B.at(i)<<" ";
  cout<<B.at(N-1)<<endl;
  return 0;
}