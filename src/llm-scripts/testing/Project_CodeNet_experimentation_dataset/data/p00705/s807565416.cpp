#include <iostream>
using namespace std;
int main(){
  int N,Q,i,I,M,data,max,result;
  int box[100]={};
  while(1){
  cin>>N>>Q;
  if(N==0||Q==0) break;
  for(i=1;i<=N;i++){
    cin>>M;
    for(I=1;I<=M;I++){
      cin>>data;
      box[data]++;
    }
  }
  max=-1;
  for(i=0;i<100;i++){
    if(max<box[i]){
      max=box[i];
      result=i;
    }
  }
  if(box[result]<Q) cout<<"0"<<endl;
  else cout<<result<<endl;
  for(i=0;i<100;i++){
    box[i]=0;
  }
  }
  return 0;
}