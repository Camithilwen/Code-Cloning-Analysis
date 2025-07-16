#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X,Y;
  cin>>N>>M>>X>>Y;
  int k=X,l=Y;
  for(int i=0;i<N;i++){
    int j=0;
    cin>>j;
    k=max(k,j);
  }
  for(int i=0;i<M;i++){
    int j=0;
    cin>>j;
    l=min(l,j);
  }
  if(k<l)
    cout<<"No War"<<endl;
  else
    cout<<"War"<<endl;
}