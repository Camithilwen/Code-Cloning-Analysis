#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int N;
  cin>>N;
  int A[200000],B[200000];
  for(int i=0;i<N;i++) cin>>A[i];
  for(int i=0;i<N;i++) cin>>B[i];
  sort(B,B+N,greater<int>());
  vector<int> same;
  for(int i=0;i<N;i++){
    if(A[i]==B[i]) same.push_back(i);
  }
  int j=0;
  int judge=0;
  for(int i=0;i<same.size();i++){
    while(A[same[i]]==B[same[i]]){
      if(j==N){
        judge++; break;
      }
      if(A[j]!=B[same[i]]&&B[j]!=B[same[i]]) swap(B[same[i]],B[j]);
      j++;
    }
    if(judge==1) break;
  }
  if(judge==0){
    cout<<"Yes"<<endl;
    for(int i=0;i<N-1;i++) cout<<B[i]<<' ';
    cout<<B[N-1]<<endl;
  }
  else cout<<"No"<<endl;
  
  return 0;
}