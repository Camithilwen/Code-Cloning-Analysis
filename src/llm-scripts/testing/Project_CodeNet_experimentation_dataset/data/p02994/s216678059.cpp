#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,L;
  cin>>N>>L;
  int A[N];
  for(int i=0;i<N;i++){
    A[i]=L+i;
  }
  int sum=0;
  if(L>=0){
    for(int i=1;i<N;i++){
      sum+=A[i];
    }
  }else if(L<=-N){
    for(int i=0;i<N-1;i++){
      sum+=A[i];
    }
    }else{
      for(int i=0;i<N;i++){
        sum+=A[i];
      }
  }
  cout<<sum<<endl;
}
    