#include<iostream>
using namespace std;

main(){
  int K,X,s,e,max_x = 1000000, min_x = -1000000;
  cin>>K>>X;
  if(X-K+1>min_x) s = X-K+1;
  else s = min_x;
  if(X+K>max_x) e=max_x;
  else e = X+K;
  for(int i=s;i<e;i++){
    cout<<i<<" ";
  }
  return 0;
}